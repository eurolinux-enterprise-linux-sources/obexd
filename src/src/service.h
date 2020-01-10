/*
 *
 *  OBEX Server
 *
 *  Copyright (C) 2007-2009  Marcel Holtmann <marcel@holtmann.org>
 *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

struct obex_service_driver {
	const char *name;
	guint16 service;
	guint8 channel;
	const guint8 *target;
	guint target_size;
	const gchar *record;
	void (*connect) (obex_t *obex, obex_object_t *obj);
	void (*progress) (obex_t *obex, obex_object_t *obj);
	void (*get) (obex_t *obex, obex_object_t *obj);
	void (*put) (obex_t *obex, obex_object_t *obj);
	gint (*chkput) (obex_t *obex, obex_object_t *obj);
	void (*setpath) (obex_t *obex, obex_object_t *obj);
	void (*disconnect) (obex_t *obex);
	void (*reset) (obex_t *obex);
};

int obex_service_driver_register(struct obex_service_driver *driver);
void obex_service_driver_unregister(struct obex_service_driver *driver);
GSList *obex_service_driver_list(guint16 services);
struct obex_service_driver *obex_service_driver_find(GSList *drivers,
					const guint8 *target, guint target_size);
