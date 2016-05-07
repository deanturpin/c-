#ifndef PXL_PXL8_H
#define PXL_PXL8_H

// PXL8 - ncurses wrapper

#include <curses.h>
#include <signal.h>
#include <unistd.h>

namespace
{
	void sig_handler(int sig)
	{
		// Tidy up ncurses on a ctrl-c
		if (sig == SIGINT)
		{
			endwin();
			_exit(0);
		}
	}
}

namespace pxl
{
	class pxl8
	{
		public:

			// Constructor - initialise ncurses
			pxl8()
			{
				// Catch ctrl-c
				signal(SIGINT, sig_handler);

				// Initialise and hide cursor
				initscr();
				erase();
				curs_set(0);
			}

			// Destructor - tidy up ncurses
			~pxl8() { endwin(); }

			// Render the internal buffer to screen and clear
			void render() const
			{
				refresh();
				erase();
			}

			// Write a point to the internal buffer
			void set(const int x, const int y) const { mvaddstr(y, x, ">"); }

			// Buffer dimensions
			int width() const { return COLS; }
			int height() const { return LINES; }
	};
}

#endif
