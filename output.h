/***************************************************************************
 *   Copyright (C) 2011 by Hans-Peter Deifel                               *
 *   hpdeifel@gmx.de                                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,      *
 *   Boston, MA 02110-1301 USA.                                            *
 ***************************************************************************/

#ifndef OUTPUT_H
#define OUTPUT_H

struct colorconf {
	char *filename;
	char *pagenum;
	char *highlight;
	char *separator;
};


struct outconf {
	int filename;
	int pagenum;
	/* FIXME this distinction doesn't belong here */
	/* controls output of color escape sequences
	 *  0: no color
	 *  1: color if stdout is a tty
	 *  2: color (regardless of stdout)
	 */
	int color;

	struct colorconf colors;
};

struct context {
	int before;
	int after;

	char *filename;
	int pagenum;

	struct outconf *out;
};

struct match {
	char *string;
	int   strlen;
	int   start;
	int   end;
};

/* print filename:pagenum:
 *
 * depending on `conf', filename and/or pagenum can be omitted.
 * `filename' is also omitted if it is NULL
 * `pagenum' is also omitted if it is < 0
 */
void print_line_prefix(const struct outconf *conf, const char *filename, const int pagenum);
void print_context_chars(const struct context *context, const struct match *match);
void print_context_line(const struct context *context, const struct match *match);

#endif
