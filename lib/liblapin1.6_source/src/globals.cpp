// Jason Brillante "Damdoshi"
// Epitech 1999-2042
//
// Lapin Library

#include			"lapin_private.h"

t_bunny_my_set_pixel		gl_bunny_my_set_pixel = NULL;
t_bunny_my_set_line		gl_bunny_my_set_line = NULL;
t_bunny_my_set_polygon		gl_bunny_my_set_polygon = NULL;
t_bunny_my_fill			gl_bunny_my_fill = NULL;
t_bunny_my_clear		gl_bunny_my_clear = NULL;
t_bunny_my_blit			gl_bunny_my_blit = NULL;

struct callback			gl_callback;
bool				gl_keyboard[sf::Keyboard::KeyCount];
t_bunny_position		gl_mouse;
bool				gl_button[sf::Mouse::ButtonCount];
bool				gl_joy_button[sf::Joystick::Count][sf::Joystick::ButtonCount];
float				gl_joy_axis[sf::Joystick::Count][sf::Joystick::AxisCount];
t_bunny_joystick		gl_joystick[sf::Joystick::Count];


const Bunny::_t_start		Bunny::Start = bunny_start;
const Bunny::_t_start_style	Bunny::StartStyle = (_t_start_style)bunny_start_style;
const Bunny::_t_stop		Bunny::Stop = bunny_stop;

const Bunny::_t_new_picture	Bunny::NewPicture = bunny_new_picture;
const Bunny::_t_load_picture	Bunny::LoadPicture = bunny_load_picture;
const Bunny::_t_new_pixelarray	Bunny::NewPixelArray = bunny_new_pixelarray;
const Bunny::_t_set_pixel	Bunny::SetPixel = bunny_set_pixel;
const Bunny::_t_set_line	Bunny::SetLine = bunny_set_line;
const Bunny::_t_set_polygon	Bunny::SetPolygon = bunny_set_polygon;
const Bunny::_t_blit		Bunny::Blit = bunny_blit;
const Bunny::_t_fill		Bunny::Fill = bunny_fill;
const Bunny::_t_draw		Bunny::Draw = bunny_draw;
const Bunny::_t_display		Bunny::Display = bunny_display;
const Bunny::_t_delete_clip	Bunny::DeleteClipable = bunny_delete_clipable;

const Bunny::_t_s_key		Bunny::SetKeyResponse = bunny_set_key_response;
const Bunny::_t_s_text		Bunny::SetTextResponse = bunny_set_text_response;
const Bunny::_t_s_click		Bunny::SetClickResponse = bunny_set_click_response;
const Bunny::_t_s_move		Bunny::SetMoveResponse = bunny_set_move_response;
const Bunny::_t_s_wheel		Bunny::SetWheelResponse = bunny_set_wheel_response;
const Bunny::_t_s_j_connect	Bunny::SetJoystickConnectResponse = bunny_set_joy_connect_response;
const Bunny::_t_s_j_button	Bunny::SetJoystickButtonResponse = bunny_set_joy_button_response;
const Bunny::_t_s_j_axis	Bunny::SetJoystickAxisResponse = bunny_set_joy_axis_response;
const Bunny::_t_s_loop		Bunny::SetLoopMainFunction = bunny_set_loop_main_function;
const Bunny::_t_loop		Bunny::Loop = bunny_loop;

const Bunny::_t_mouse		Bunny::MousePosition = (_t_mouse)bunny_get_mouse_position;
const Bunny::_t_button		Bunny::MouseButton = bunny_get_mouse_button;
const Bunny::_t_keystate	Bunny::Keyboard = bunny_get_keyboard;
const Bunny::_t_joy_button	Bunny::JoyButton = bunny_get_joy_button;
const Bunny::_t_joy_axis	Bunny::JoyAxis = bunny_get_joy_axis;

const Bunny::_t_set_context	Bunny::SetContext = bunny_set_context;
const Bunny::_t_get_context	Bunny::GetContext = bunny_get_context;

const Bunny::_t_music		Bunny::LoadMusic = bunny_load_music;
const Bunny::_t_effect		Bunny::LoadEffect = bunny_load_effect;
const Bunny::_t_volume		Bunny::SetVolume = bunny_sound_volume;
const Bunny::_t_pitch		Bunny::SetPitch = bunny_sound_pitch;
const Bunny::_t_snd_loop	Bunny::SetLoop = bunny_sound_loop;
const Bunny::_t_play_snd	Bunny::PlaySound = bunny_sound_play;
const Bunny::_t_stop_snd	Bunny::StopSound = bunny_sound_stop;
const Bunny::_t_delete_snd	Bunny::DeleteSound = bunny_delete_sound;

const char			*default_scope = NULL;
const char			*Bunny::DefaultScope = NULL;

const char			*erase_scope = NULL;
const char			*Bunny::EraseScope = NULL;

const unsigned int		erase_field = UINT_MAX;
const unsigned int		Bunny::EraseField = UINT_MAX;

const char			*erase_index = NULL;
const char			*Bunny::EraseIndex = NULL;

const char			*last_scope = NULL;
const char			*Bunny::LastScope = NULL;

const Bunny::_t_i_new		Bunny::NewIni = bunny_new_ini;
const Bunny::_t_i_load		Bunny::LoadIni = bunny_load_ini;
const Bunny::_t_i_save		Bunny::SaveIni = bunny_save_ini;
const Bunny::_t_i_get_field	Bunny::GetField = bunny_ini_get_field;
const Bunny::_t_i_set_field	Bunny::SetField = bunny_ini_set_field;
const Bunny::_t_i_delete	Bunny::DeleteIni = bunny_delete_ini;
const Bunny::_t_i_first		Bunny::FirstScope = bunny_ini_first;
const Bunny::_t_i_scope_name	Bunny::GetScopeName = bunny_ini_scope_name;
const Bunny::_t_i_next		Bunny::NextScope = bunny_ini_next;
const Bunny::_t_i_scope_get	Bunny::ScopeGetField = bunny_ini_scope_get_field;
const Bunny::_t_i_scope_set	Bunny::ScopeSetField = bunny_ini_scope_set_field;
