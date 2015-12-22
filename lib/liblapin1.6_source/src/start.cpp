// Jason Brillante "Damdoshi"
// Epitech 1999-2042
//
// Lapin library

#include		<setjmp.h>
#include		<signal.h>
#include		<string.h>
#include		<string>
#include		"lapin_private.h"

t_bunny_window		*bunny_start(unsigned int		width,
				     unsigned int		height,
				     bool			fullscreen,
				     const char			*winname)
{
  return (bunny_start_style(width, height, fullscreen ? FULLSCREEN : DEFAULT_WIN_STYLE, winname));
}

static jmp_buf		jump_buffer;

static void		sigabort(int				unused)
{
  (void)unused;
  longjmp(jump_buffer, 1);
}

static bool		do_the_allocation(struct bunny_window	*win)
{
  return ((win->window = new (std::nothrow) sf::RenderWindow) != NULL);
}

static bool		create_window(struct bunny_window	*win)
{
  sighandler_t		oldsig;

  oldsig = signal(SIGABRT,  sigabort);
  if (setjmp(jump_buffer) != 0)
    {
      // Because rollbacked...
      signal(SIGABRT, oldsig);
      return (false);
    }
  if (do_the_allocation(win) == false)
    {
      signal(SIGABRT, oldsig);
      return (false);
    }
  signal(SIGABRT, oldsig);
  return (true);
}

t_bunny_window		*bunny_start_style(unsigned int		width,
					   unsigned int		height,
					   t_bunny_window_style	winstyle,
					   const char		*window_name)
{
  sf::ContextSettings	settings;
  struct bunny_window	*win;
  int			i;
  
  if ((win = new (std::nothrow) bunny_window) == NULL)
    goto Fail;
  if (create_window(win) == false)
    goto FailStruct;

  settings.antialiasingLevel = 4;
  win->window->create(sf::VideoMode(width, height, 32), strdup(window_name), winstyle, settings);

  win->window->setVerticalSyncEnabled(false);
  win->type = WINDOW;
  win->width = width;
  win->height = height;
  win->window_name = window_name;

  for (i = 0; i < LAST_BUNNY_JOYSTICK; ++i)
    if (sf::Joystick::isConnected(i))
      {
	sf::Joystick::Identification	id;
	int				j;

	gl_joystick[i].connected = true;
	gl_joystick[i].name = strdup(id.name.toAnsiString().c_str());
	gl_joystick[i].vendor = id.vendorId;
	gl_joystick[i].product = id.productId;
	gl_joystick[i].nb_button = sf::Joystick::getButtonCount(i);
	gl_joystick[i].axis = 0;
	for (j = 0; j < sf::Joystick::AxisCount; ++j)
	  gl_joystick[i].axis |= (sf::Joystick::hasAxis(i, (sf::Joystick::Axis)j) ? 1 : 0) << j;
      }

  return ((t_bunny_window*)win);

 FailStruct:
  delete win;
 Fail:
  return (NULL);
}
