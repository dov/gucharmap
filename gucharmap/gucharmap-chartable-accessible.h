/*
 * Copyright (c) 2003  Sun Microsystems Inc.
 * Copyright (C) 2007  Christian Persch
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef GUCHARMAP_CHARTABLE_ACCESSIBLE_H
#define GUCHARMAP_CHARTABLE_ACCESSIBLE_H

#include <gtk/gtkaccessible.h>

#include "gucharmap-chartable.h"

G_BEGIN_DECLS

#define GUCHARMAP_CHARTABLE_ACCESSIBLE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), gucharmap_chartable_accessible_get_type (), GucharmapChartableAccessible))
#define GUCHARMAP_CHARTABLE_ACCESSIBLE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), gucharmap_chartable_accessible_get_type (), GucharmapChartableAccessibleClass))
#define IS_GUCHARMAP_CHARTABLE_ACCESSIBLE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), gucharmap_chartable_accessible_get_type ()))
#define IS_GUCHARMAP_CHARTABLE_ACCESSIBLE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), gucharmap_chartable_accessible_get_type ()))
#define GUCHARMAP_CHARTABLE_ACCESSIBLE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), gucharmap_chartable_accessible_get_type (), GucharmapChartableAccessibleClass))

typedef struct _GucharmapChartableAccessible      GucharmapChartableAccessible;
typedef struct _GucharmapChartableAccessibleClass GucharmapChartableAccessibleClass;

GType gucharmap_chartable_accessible_get_type (void);

AtkObject *gucharmap_chartable_accessible_new (GucharmapChartable *chartable);

G_END_DECLS

#endif /* !GUCHARMAP_CHARTABLE_ACCESSIBLE_H */