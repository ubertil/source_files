/*
** Jason Brillante "Damdoshi" brilla_a brilla_b
** Epitech 1999-2042
**
**
** Bibliotheque Lapin
*/

#ifndef			__LAPIN_PRIVATE_H__
# define		__LAPIN_PRIVATE_H__
# include		<SFML/Graphics.hpp>
# include		<SFML/Audio.hpp>
# include		"Ini.hpp"
# include		"lapin_enum.h"
# include		"lapin.h"

struct			memtree;
struct			memchunk
{
  size_t		border0;
  struct memtree	*tree;
  struct memchunk	*prev;
  struct memchunk	*next;
  size_t		border1;
};

struct			memtree
{
  size_t		chunk_size;
  struct memchunk	*allocated;
  struct memchunk	*freed;
  struct memtree	*greater;
  struct memtree	*lesser;
};

struct			memhead
{
  size_t		alloc_count;
  size_t		total_count;
  size_t		alloc;
  size_t		total;
  struct memtree	*first;
  void			*limit;
  char			*last_position;
};

struct memchunk		*get_node(struct memhead		*head,
				       size_t			data);

struct			callback
{
  t_bunny_key		key;
  t_bunny_type		type;
  t_bunny_click		click;
  t_bunny_move		move;
  t_bunny_wheel		wheel;
  t_bunny_joy_connect	connect;
  t_bunny_joy_button	button;
  t_bunny_joy_axis	axis;
  t_bunny_loop		loop;
};

enum			_buffer_type
  {
    WINDOW,
    GRAPHIC_RAM,
    SYSTEM_RAM
  };

struct			bunny_window
{
  size_t		type;
  sf::RenderWindow	*window;
  unsigned int		width;
  unsigned int		height;
  const char		*window_name;
};

struct			bunny_picture
{
  size_t		type;
  sf::RenderTexture	*texture;
  unsigned int		width;
  unsigned int		height;
  sf::IntRect		rect;
  double		x_origin;
  double		y_origin;
  double		x_scale;
  double		y_scale;
  double		rotation;
  const sf::Texture	*tex;
  sf::Sprite		sprite;
};

struct			bunny_pixelarray
{
  size_t		type;
  size_t		unused;
  unsigned int		width;
  unsigned int		height;
  sf::IntRect		rect;
  double		x_origin;
  double		y_origin;
  double		x_scale;
  double		y_scale;
  double		rotation;
  unsigned int		*rawpixels;
  sf::Image		image;
  sf::Texture		tex;
  sf::Sprite		sprite;
};

enum			_music_or_sound
  {
    MUSIC,
    EFFECT
  };

struct			bunny_music
{
  enum _music_or_sound	type;
  sf::Music		music;
};

struct			bunny_effect
{
  enum _music_or_sound	type;
  sf::SoundBuffer	effect;
  sf::Sound		sound;
};

extern struct callback	gl_callback;
extern bool		gl_keyboard[sf::Keyboard::KeyCount];
extern t_bunny_position	gl_mouse;
extern bool		gl_button[sf::Mouse::ButtonCount];
extern bool		gl_joy_button[sf::Joystick::Count][sf::Joystick::ButtonCount];
extern float		gl_joy_axis[sf::Joystick::Count][sf::Joystick::AxisCount];
extern t_bunny_joystick	gl_joystick[sf::Joystick::Count];

#endif	/*		__LAPIN_PRIVATE_H__	*/
