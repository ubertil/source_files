/*
** Jason Brillante "Damdoshi" brilla_a brilla_b
** Epitech 1999-2042
**
**
** Bibliotheque Lapin
*/

/*
** The Lapin Library needs to be linked like this:
** -L[liblapin_path] -llapin
** -L[libsfml_path] -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl
** sfml_path may be /usr/lib64, /usr/lib, /usr/local/lib, /home/${USER}/.froot/lib
** liblapin_path may be /usr/local/lib, /home/${USER}/.froot/include
** You will need to add a -I[sfmlinclude_path] or -I[liblapin_path] too
*/

#ifndef				__LAPIN_H__
# define			__LAPIN_H__
# include			<stdbool.h>
# include			<stdarg.h>
# include			<stdint.h>
# include			<stdlib.h>
# include			<limits.h>
# include			"lapin_enum.h"

# ifdef				__cplusplus
extern "C"
{
# endif


/*
** *****
** ****
** *** SYSTEM
** **
** *
*/

# ifdef				LAPIN_ALLOCATOR_OVERLOAD
#  define			malloc			bunny_malloc
#  define			calloc			bunny_calloc
#  define			realloc			bunny_realloc
#  define			free			bunny_free
# endif
# ifdef				LAPIN_ALLOCATOR_DEACTIVATED
#  define			bunny_malloc		malloc
#  define			bunny_calloc		calloc
#  define			bunny_realloc		realloc
#  define			bunny_free		free
# endif
# ifndef			M_PI
#  define			M_PI			3.14159265358979323846
# endif

void				*bunny_malloc(size_t	size);
void				*bunny_calloc(size_t	nmemb,
					      size_t	size);
void				*bunny_realloc(void	*ptr,
					       size_t	newsize);
void				bunny_free(void		*ptr);
extern int			memory_check;


/*
** *****
** ****
** *** GRAPHICS
** **
** *
*/

# define			TO_ALPHA(a)		(((a) & 0xFF) << (ALPHA_CMP * 8))
# define			GET_COLOR(c)		(c & ~TO_ALPHA(255))
# define			ALPHA(a, c)		(TO_ALPHA(a) | GET_COLOR(c))

# define			BLACK			(255 << (ALPHA_CMP * 8))

# define			RED			(BLACK | 255 << (RED_CMP * 8))
# define			GREEN			(BLACK | 255 << (GREEN_CMP * 8))
# define			BLUE			(BLACK | 255 << (BLUE_CMP * 8))

# define			PURPLE			(RED | BLUE)
# define			TEAL			(GREEN | BLUE)
# define			YELLOW			(RED | GREEN)

# define			WHITE			(RED | GREEN | BLUE)

/*
** My favorite color <3 (well, with red and black)
*/
#  define			PINK			0xFF7777FF

typedef enum			e_rgb
  {
    RED_CMP			= 0,
    GREEN_CMP			= 1,
    BLUE_CMP			= 2,
    ALPHA_CMP			= 3
  }				t_rgb;

typedef union			u_color
{
  unsigned int			full;
  unsigned char			argb[4];
  char				mod[4];
}				t_color;

typedef struct			s_bunny_position
{
  int				x;
  int				y;
}				t_bunny_position;

typedef struct			s_bunny_accurate_position
{
  double			x;
  double			y;
}				t_bunny_accurate_position;

typedef void			t_bunny_shader;

/*
** Bunny buffer is a graphical buffer. Window and picture both got one.
** Pixels is (width * height * sizeof(unsigned int)) length allocated,
** you can freely write datas in.
**
** Picture contain additional datas: 
** Informations about a clip: a small portion of picture
** that will be displayed when you blit it on window. Default values make
** the buffer fully displayed.
**
** Start create a window
** Start Style create a window with a specific style
** New PixelArray create an empty picture that can be accessed like an array
** New Picture create an empty picture
** Load picture load a picture file (.bmp, .png, .gif, .jpg) into a picture
** Set Pixel draw a pixel at a given position with a precised color
** Line draw a line thanks to position and color (array at least 2 struct long)
** Polygon draw a line thanks to position and color (array at least 3 struct long)
** Fill fill the clip inside buffer, it add color over the existing one
** Clear fill the clip inside buffer, it replace existing color by a new one
** Blit draw the clip from picture into window at position
** Blit shader apply a special effect to the picture while blitted. Pay attention with this one.
**   Blit shader does not work on pixelarray.
** Draw compute all blit done on a picture
** Display display graphcis in window
**
** Delete delete a clipable
** Stop destroy the window
**
**
** /!\ Pay attention to which function you are allowed to use and which one you ain't /!\
**
*/

/*
** Do not use s_bunny_buffer directly. Use bunny_window and bunny_picture
*/

typedef struct			s_bunny_buffer
{
  const char			_private[2 * sizeof(size_t)];
  int				width;
  int				height;
}				t_bunny_buffer;

typedef struct			s_bunny_window
{
  t_bunny_buffer		buffer;
  const char * const		name;
}				t_bunny_window;

typedef struct			s_bunny_clipable
{
  t_bunny_buffer		buffer;
  int				clip_x_position;
  int				clip_y_position;
  int				clip_width;
  int				clip_height;
  t_bunny_accurate_position	origin;
  t_bunny_accurate_position	scale;
  double			rotation;
}				t_bunny_clipable;

typedef t_bunny_clipable	t_bunny_picture;

typedef struct			s_bunny_pixelarray
{
  t_bunny_clipable		clipable;
  void * const			pixels;
}				t_bunny_pixelarray;

typedef enum			e_bunny_window_style
  {
    NO_BORDER			= 0,
    TITLEBAR			= 1,
    RESIZE_BUTTON		= 2,
    CLOSE_BUTTON		= 4,
    FULLSCREEN			= 8,
    DEFAULT_WIN_STYLE		= TITLEBAR | RESIZE_BUTTON | CLOSE_BUTTON
  }				t_bunny_window_style;

t_bunny_window			*bunny_start(unsigned int			width,
					     unsigned int			height,
					     bool				fullscreen,
					     const char				*window_name);

t_bunny_window			*bunny_start_style(unsigned int			width,
						   unsigned int			height,
						   t_bunny_window_style		winstyle,
						   const char			*window_name);

t_bunny_pixelarray		*bunny_new_pixelarray(unsigned int		width,
						      unsigned int		height);
t_bunny_picture			*bunny_new_picture(unsigned int			width,
						   unsigned int			height);
t_bunny_picture			*bunny_load_picture(const char			*file);
t_bunny_pixelarray		*bunny_load_pixelarray(const char		*file);

void				bunny_set_pixel(t_bunny_buffer			*buffer,
						t_bunny_position		position,
						unsigned int			color);
void				bunny_set_line(t_bunny_buffer			*buffer,
					       const t_bunny_position		*coord,
					       const unsigned int		*color);
void				bunny_set_polygon(t_bunny_buffer		*buffer,
						  const t_bunny_position	*coord,
						  const unsigned int		*color);
void				bunny_fill(t_bunny_buffer			*buffer,
					   unsigned int				color);
void				bunny_clear(t_bunny_buffer			*buffer,
					    unsigned int			color);

void				bunny_blit(t_bunny_buffer			*buffer,
					   const t_bunny_clipable		*picture,
					   const t_bunny_position		*position);
void				bunny_blit_shader(t_bunny_buffer		*buffer,
						  const t_bunny_picture		*picture,
						  const t_bunny_position	*position,
						  const t_bunny_shader		*shader);

void				bunny_draw(const t_bunny_picture		*picture);
void				bunny_display(const t_bunny_window		*window);

  void				bunny_delete_clipable(t_bunny_clipable		*picture);
void				bunny_stop(t_bunny_window			*window);

/*
** Make the library richer by adding your function to write inside t_bunny_pixelarray
** by setting these function pointers.
** Using these functions pointers without setting it lead to segmentation fault.
*/

typedef void			(*t_bunny_my_set_pixel)(t_bunny_pixelarray	*pix,
							t_bunny_position	pos,
							unsigned int		color);
typedef void			(*t_bunny_my_set_line)(t_bunny_pixelarray	*pix,
						       const t_bunny_position	*coord,
						       const unsigned int	*color);
typedef void			(*t_bunny_my_set_polygon)(t_bunny_pixelarray	*pix,
							  const t_bunny_position *coord,
							  const unsigned int	*color);
typedef void			(*t_bunny_my_fill)(t_bunny_pixelarray		*pix,
						   unsigned int			color);
typedef void			(*t_bunny_my_clear)(t_bunny_pixelarray		*pix,
						    unsigned int		color);
typedef void			(*t_bunny_my_blit)(t_bunny_pixelarray		*out,
						   const t_bunny_pixelarray	*in,
						   const t_bunny_position	*pos);

extern t_bunny_my_set_pixel	gl_bunny_my_set_pixel;
extern t_bunny_my_set_line	gl_bunny_my_set_line;
extern t_bunny_my_set_polygon	gl_bunny_my_set_polygon;
extern t_bunny_my_fill		gl_bunny_my_fill;
extern t_bunny_my_clear		gl_bunny_my_clear;
extern t_bunny_my_blit		gl_bunny_my_blit;

/*
** Vector Font
*/

typedef struct			s_bunny_line_coord
{
  int				x0;
  int				y0;
  int				x1;
  int				y1;
}				t_bunny_line_coord;

typedef struct			s_bunny_letter
{
  int				nb_edge;
  t_bunny_line_coord		lines[5];
}				t_bunny_letter;

extern const t_bunny_letter	gl_vector_font[LAST_BUNNY_FONT];

/*
** Shaders
** Pattern may be:
** 1f, 2f, 3f, 4cmp, col, tra, pic, cur
** Corresponding to 1 float to 3 float, 4 unsigned char (order is t_color order), 1 unsigned int,
** a pointer to t_bunny_transform
** a pointer to t_bunny_picture
** or nothing
*/

typedef enum			e_bunny_variable_type
  {
    BVT_1_FLOAT,
    BVT_2_FLOAT,
    BVT_3_FLOAT,
    BVT_4_COLOR_COMPONENT,
    BVT_FULL_COLOR,
    BVT_TRANSFORM,
    BVT_PICTURE,
    BVT_CURRENT_TEXTURE_TYPE
  }				t_bunny_variable_type;
typedef struct			s_bunny_transform
{
  t_bunny_accurate_position	origin;
  t_bunny_accurate_position	translation;
  t_bunny_accurate_position	scale; 
  double			rotation;
}				t_bunny_transform;
  
bool				bunny_is_shader_available(void);
t_bunny_shader			*bunny_new_shader(void);
bool				bunny_load_shader(t_bunny_shader		*shader,
						  const char			*vertex_file,
						  const char			*fragment_file);
  void				bunny_shader_set_variable(t_bunny_shader	*shader,
							  const char		*var_name,
							  t_bunny_variable_type	type,
							  ...);
void				bunny_delete_shader(t_bunny_shader		*shader);
  
/*
** *****
** ****
** *** EVENTS
** **
** *
*/

/*
** Bunny set * response are functions that takes a pointer to function as main value.
** This pointer to function will be called when an event of the concerned nature occured
**
** These functions must return a bunny_response which allow user to exit.
** Exit on error and exit on success can be send by programer. Exit on cross mean exit by closing window.
** Click and key use the event state enum: key and buttons can go down and go up
** 
** Key is when a key is pressed or release
** Click is when a mouse button is pressed or released
** Move is when the mouse move. Sent datas are relative to the previous position.
** Loop main function is called at each loop
**
** Loop launch the main loop. The refresh frequency must be sent, also a generic
** pointer may be gived. This pointer will be sent to every function that respond
** to event
**
** Get mouse return a pointer on the absolut position of the mouse
** Get keyboard return a pointer on an array max length if set_key_response's keysym max value
** and bool is true if the key is down
**
** Sending a null pointer to set_response functions disable the response
**
** GetEventContext save all event response inside a t_bunny_context
** SetEventContext set all event response from a t_bunny_context
**
** The field axis in the t_bunny_joystick structure is a bitmask with t_bunny_axis
**
*/

typedef enum			e_bunny_response
  {
    EXIT_ON_ERROR,
    EXIT_ON_CROSS,
    EXIT_ON_SUCCESS,
    GO_ON
  }				t_bunny_response;
typedef enum			e_bunny_event_state
  {
    GO_DOWN,
    GO_UP,
    CONNECTED			= GO_DOWN,
    DISCONNECTED		= GO_UP
  }				t_bunny_event_state;

typedef struct			s_bunny_joystick
{
  bool				connected;
  const char			*name;
  unsigned int			vendor;
  unsigned int			product;
  unsigned int			nb_button;
  unsigned char			axis;
}				t_bunny_joystick;

typedef t_bunny_response	(*t_bunny_key)(t_bunny_event_state		state,
					       t_bunny_keysym			keysym,
					       void				*your_data);
typedef t_bunny_response	(*t_bunny_type)(uint32_t			unicode,
						void				*your_data);
typedef t_bunny_response	(*t_bunny_click)(t_bunny_event_state		state,
						 t_bunny_mousebutton		button,
						 void				*your_data);
typedef t_bunny_response	(*t_bunny_move)(const t_bunny_position		*relative,
						void				*your_data);
typedef t_bunny_response	(*t_bunny_wheel)(int				wheelid,
						 int				delta,
						 void				*your_data);
typedef t_bunny_response	(*t_bunny_joy_connect)(t_bunny_event_state	state,
						       int			joyid,
						       const t_bunny_joystick	*joyinfo,
						       void			*your_data);
typedef t_bunny_response	(*t_bunny_joy_axis)(int				joyid,
						    t_bunny_axis		axis,
						    float			value,
						    void			*your_data);
typedef t_bunny_response	(*t_bunny_joy_button)(t_bunny_event_state	state,
						      int			joyid,
						      int			button,
						      void			*your_data);
typedef t_bunny_response	(*t_bunny_loop)(void				*your_data);

void				bunny_set_key_response(t_bunny_key		key);
void				bunny_set_text_response(t_bunny_type		type);
void				bunny_set_click_response(t_bunny_click		click);
void				bunny_set_move_response(t_bunny_move		move);
void				bunny_set_wheel_response(t_bunny_wheel		wheel);
void				bunny_set_joy_connect_response(t_bunny_joy_connect joystick);
void				bunny_set_joy_button_response(t_bunny_joy_button joystick);
void				bunny_set_joy_axis_response(t_bunny_joy_axis	joystick);
void				bunny_set_loop_main_function(t_bunny_loop	loop);
t_bunny_response		bunny_loop(t_bunny_window			*window,
					   unsigned char			refresh_frequency,
					   void					*your_data);

const bool			*bunny_get_keyboard(void);
const t_bunny_position		*bunny_get_mouse_position(void);
const bool			*bunny_get_mouse_button(void);
const t_bunny_joystick		*bunny_get_joy_info(int				id);
const bool			(*bunny_get_joy_button(void))[LAST_BUNNY_BUTTON];
const float			(*bunny_get_joy_axis(void))[LAST_BUNNY_AXIS];

/*
** Utils...
*/
  
typedef struct			s_bunny_context
{
  t_bunny_key			key;
  t_bunny_type			type;
  t_bunny_click			click;
  t_bunny_move			move;
  t_bunny_wheel			wheel;
  t_bunny_joy_connect		connect;
  t_bunny_joy_button		button;
  t_bunny_joy_axis		axis;
  t_bunny_loop			loop;
}				t_bunny_context;

void				bunny_set_context(const t_bunny_context		*context);
void				bunny_get_context(t_bunny_context		*context);

void				bunny_set_key_repeat(t_bunny_window		*win,
						     bool			active);
void				bunny_set_mouse_visibility(const t_bunny_window	*win,
							   bool			visible);
void				bunny_set_mouse_position_window(const t_bunny_window *win,
								int		x,
								int		y);
void				bunny_set_mouse_position(int			x,
							 int			y);
void				bunny_request_focus(const t_bunny_window	*win);

/*
** *****
** ****
** *** SOUND
** **
** *
*/

/*
** Load music load music from an ogg file. Use it for long sound.
** Load effect load a sound from an ogg file. Use it for short sound.
**
** Volume change volume. Value must be between 0 and 100.
** Pitch change pitch, making the sound more acute or grave. Base value is 1
** Loop set if the sound loop after its end
**
** Play make the sound to be played
** Stop stop the sound
** Delete delete the sound
*/

typedef void			t_bunny_sound;

typedef void			t_bunny_music;
typedef void			t_bunny_effect;

t_bunny_music			*bunny_load_music(const char			*file);
t_bunny_effect			*bunny_load_effect(const char			*file);

void				bunny_sound_volume(t_bunny_sound		*sound,
						   double			volume);
void				bunny_sound_pitch(t_bunny_sound			*sound,
						  double			pitch);
  void				bunny_sound_loop(t_bunny_sound			*sound,
						 bool				loop);

void				bunny_sound_play(t_bunny_sound			*sound);
void				bunny_sound_stop(t_bunny_sound			*sound);
void				bunny_delete_sound(t_bunny_sound		*sound);

/*
** *****
** ****
** *** CONFIGURATION
** **
** *
*/

/*
** Load ini load a ini formatted datas from a text file.
** Save ini save the content of the structure inside a file.
** Get Field return a value from the readed file. Consider this grammar:
**
** [Scope]
**  Field = index0, index1, index2
**
** If no scope were defined, you can send NULL as scope parameter.
** Return NULL if the data does not exist.
**
** Set field allow you to set a value inside the readed file. The value
** is not stored directly, a copy is made. Send NULL as value if you want to
** remove a value. It return false on error.
**
** Ini First return a t_bunny_ini_scope pointer to the beginning of the scope list. NULL if empty.
** Ini ScopeName return the name of the scope
** Ini Next go from the current scope to the next. NULL if it was the last one.
** Ini Scope Get Field is like Get Field, but with a bunny_ini_scope
** Ini Scope Set Field is like Set Field, but with a bunny_ini_scope
**
** Delete ini destroy the loaded configuration
**
*/

typedef void			t_bunny_ini;
typedef void			t_bunny_ini_scope;

extern const char		*default_scope;
extern const char		*erase_scope;
extern const unsigned int	erase_field;
extern const char		*erase_index;
extern const char		*last_scope;

t_bunny_ini			*bunny_new_ini(void);
t_bunny_ini			*bunny_load_ini(const char			*file);
bool				bunny_save_ini(t_bunny_ini			*ini,
					       const char			*file);

const char			*bunny_ini_get_field(const t_bunny_ini		*ini,
						     const char			*scope,
						     const char			*field,
						     unsigned int		index);
void				bunny_ini_set_field(t_bunny_ini			*ini,
						    const char			*scope,
						    const char			*field,
						    unsigned int		index,
						    const char			*value);

t_bunny_ini_scope		*bunny_ini_first(t_bunny_ini			*ini);
const char			*bunny_ini_scope_name(const t_bunny_ini		*ini,
						      const t_bunny_ini_scope	*scope);
t_bunny_ini_scope		*bunny_ini_next(t_bunny_ini			*ini,
						t_bunny_ini_scope		*scope);
const char			*bunny_ini_scope_get_field(const t_bunny_ini_scope *scope,
							   const char		*field,
							   unsigned int		index);
void				bunny_ini_scope_set_field(t_bunny_ini_scope	*scope,
							  const char		*field,
							  unsigned int		index,
							  const char		*value);

void				bunny_delete_ini(t_bunny_ini			*ini);

# ifdef				__cplusplus
}

//////// Read this part only if you use C++
///////
////// //====   //      //
///// //       //      //
//// //    ======== ========
/// //       //       //
// //====   //       //

namespace			Bunny
{
  ////
  /// Graphics
  //
  typedef t_rgb			RGB;
  typedef t_color		Color;
  typedef t_bunny_buffer	Buffer;
  typedef t_bunny_window	Window;
  typedef t_bunny_clipable	Clipable;
  typedef t_bunny_picture	Picture;
  typedef t_bunny_pixelarray	PixelArray;
  typedef t_bunny_position	Position;
  typedef t_bunny_accurate_position AccuratePosition;
  typedef t_bunny_letter	Letter;

  /// Typedef only used to create C++ embed of C functions
  typedef Window		*(*_t_start)(unsigned int			w,
					     unsigned int			h,
					     bool				f,
					     const char				*n);
  typedef Window		*(*_t_start_style)(unsigned int			w,
						   unsigned int			h,
						   unsigned int			winstyle,
						   const char			*window_name);
  typedef Picture		*(*_t_new_picture)(unsigned int			w,
						   unsigned int			h);
  typedef PixelArray		*(*_t_new_pixelarray)(unsigned int		w,
						      unsigned int		h);
  typedef Picture		*(*_t_load_picture)(const char			*s);

  typedef void			(*_t_set_pixel)(Buffer				*b,
						Position			p,
						unsigned int			c);
  typedef void			(*_t_set_line)(Buffer				*b,
					       const Position			*p,
					       const unsigned int		*c);
  typedef void			(*_t_set_polygon)(Buffer			*b,
						  const Position		*p,
						  const unsigned int		*c);
  typedef void			(*_t_blit)(Buffer				*c,
					   const Picture			*s,
					   const Position			*p);
  typedef void			(*_t_fill)(Buffer				*b,
					   unsigned int				c);
  typedef void			(*_t_draw)(const Picture			*w);
  typedef void			(*_t_display)(const Window			*w);
  typedef void			(*_t_delete_clip)(Clipable			*p);
  typedef void			(*_t_stop)(Window				*w);

  extern const _t_start		Start;
  extern const _t_start_style	StartStyle;
  extern const _t_stop		Stop;

  extern const _t_new_picture	NewPicture;
  extern const _t_load_picture	LoadPicture;
  extern const _t_new_pixelarray NewPixelArray;
  extern const _t_set_pixel	SetPixel;
  extern const _t_set_line	SetLine;
  extern const _t_set_polygon	SetPolygon;
  extern const _t_blit		Blit;
  extern const _t_fill		Fill;
  extern const _t_draw		Draw;
  extern const _t_display	Display;
  extern const _t_delete_clip	DeleteClipable;

  //// Event
  ///
  //
  typedef t_bunny_response	Response;
  typedef t_bunny_event_state	EventState;
  typedef t_bunny_key		Key;
  typedef t_bunny_type		Text;
  typedef t_bunny_click		Click;
  typedef t_bunny_move		Move;
  typedef t_bunny_wheel		Wheel;
  typedef t_bunny_joy_connect	JoystickConnect;
  typedef t_bunny_joy_axis	JoystickAxis;
  typedef t_bunny_joy_button	JoystickButton;
  typedef t_bunny_loop		MainLoop;

  /// Typedef only used to create C++ embed of C functions
  typedef void			(*_t_s_key)(Key					k);
  typedef void			(*_t_s_text)(Text				t);
  typedef void			(*_t_s_click)(Click				c);
  typedef void			(*_t_s_move)(Move				m);
  typedef void			(*_t_s_wheel)(Wheel				w);
  typedef void			(*_t_s_j_connect)(JoystickConnect		jc);
  typedef void			(*_t_s_j_button)(JoystickButton			jb);
  typedef void			(*_t_s_j_axis)(JoystickAxis			ja);
  typedef void			(*_t_s_loop)(MainLoop				l);
  typedef Response		(*_t_loop)(Window				*w,
					   unsigned char			f,
					   void					*d);
  typedef const Position	&(*_t_mouse)(void);
  typedef const bool		*(*_t_button)(void);
  typedef const bool		*(*_t_keystate)(void);
  typedef const bool		(*(*_t_joy_button)(void))[LAST_BUNNY_BUTTON];
  typedef const float		(*(*_t_joy_axis)(void))[LAST_BUNNY_AXIS];

  extern const _t_s_key		SetKeyResponse;
  extern const _t_s_text	SetTextResponse;
  extern const _t_s_click	SetClickResponse;
  extern const _t_s_move	SetMoveResponse;
  extern const _t_s_wheel	SetWheelResponse;
  extern const _t_s_j_connect	SetJoystickConnectResponse;
  extern const _t_s_j_button	SetJoystickButtonResponse;
  extern const _t_s_j_axis	SetJoystickAxisResponse;
  extern const _t_s_loop	SetLoopMainFunction;
  extern const _t_loop		Loop;

  extern const _t_mouse		MousePosition;
  extern const _t_button	MouseButton;
  extern const _t_keystate	Keyboard;
  extern const _t_joy_button	JoyButton;
  extern const _t_joy_axis	JoyAxis;

  typedef t_bunny_context	Context;
  typedef void			(*_t_set_context)(const Context		*c);
  typedef void			(*_t_get_context)(Context		*c);
  extern const _t_set_context	SetContext;
  extern const _t_get_context	GetContext;

  //// Sound
  ///
  //
  typedef t_bunny_sound		Sound;
  typedef t_bunny_music		Music;
  typedef t_bunny_effect	Effect;

  /// Typedef only used to create C++ embed of C functions
  typedef Music			*(*_t_music)(const char				*file);
  typedef Effect		*(*_t_effect)(const char			*file);
  typedef void			(*_t_volume)(Sound				*s,
					     double				v);
  typedef void			(*_t_pitch)(Sound				*s,
					    double				p);
  typedef void			(*_t_snd_loop)(Sound				*s,
					       bool				l);
  typedef void			(*_t_play_snd)(Sound				*s);
  typedef void			(*_t_stop_snd)(Sound				*s);
  typedef void			(*_t_delete_snd)(Sound				*s);

  extern const _t_music		LoadMusic;
  extern const _t_effect	LoadEffect;
  extern const _t_volume	SetVolume;
  extern const _t_pitch		SetPitch;
  extern const _t_snd_loop	SetLoop;
  extern const _t_play_snd	PlaySound;
  extern const _t_stop_snd	StopSound;
  extern const _t_delete_snd	DeleteSound;

  //// Configuration
  ///
  //
  typedef t_bunny_ini		Ini;
  typedef t_bunny_ini_scope	Scope;

  extern const char		*DefaultScope;
  extern const char		*EraseScope;
  extern const unsigned int	EraseField;
  extern const char		*EraseIndex;
  extern const char		*LastScope;

  typedef Ini			*(*_t_i_new)(void);
  typedef Ini			*(*_t_i_load)(const char			*file);
  typedef bool			(*_t_i_save)(Ini				*ini,
					     const char				*file);
  typedef const char		*(*_t_i_get_field)(const Ini			*ini,
						   const char			*scope,
						   const char			*field,
						   unsigned int			index);
  typedef void			(*_t_i_set_field)(Ini				*ini,
						  const char			*scope,
						  const char			*field,
						  unsigned int			index,
						  const char			*value);
  typedef void			(*_t_i_delete)(Ini				*ini);

  typedef Scope			*(*_t_i_first)(Ini				*ini);
  typedef const char		*(*_t_i_scope_name)(const Ini			*ini,
						    const Scope			*scope);
  typedef Scope			*(*_t_i_next)(Ini				*ini,
					      Scope				*scope);
  typedef const char		*(*_t_i_scope_get)(const Scope			*scope,
						   const char			*field,
						   unsigned int			index);
  typedef void			(*_t_i_scope_set)(Scope				*scope,
						  const char			*field,
						  unsigned int			index,
						  const char			*value);

  extern const _t_i_new		NewIni;
  extern const _t_i_load	LoadIni;
  extern const _t_i_save	SaveIni;
  extern const _t_i_get_field	GetField;
  extern const _t_i_set_field	SetField;
  extern const _t_i_delete	DeleteIni;

  extern const _t_i_first	FirstScope;
  extern const _t_i_scope_name	GetScopeName;
  extern const _t_i_next	NextScope;
  extern const _t_i_scope_get	ScopeGetField;
  extern const _t_i_scope_set	ScopeSetField;

}
# endif
#endif	/*			__BUNNY_LIB_H__		*/
