/* $Id: gucharmap-chapters.h 1376 2007-12-03 21:42:48Z chpe $ */
/*
 * Copyright (c) 2004 Noah Levitt
 * Copyright (C) 2007 Christian Persch
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02110-1301  USA
 */

#ifndef GUCHARMAP_CHAPTERS_MODEL_H
#define GUCHARMAP_CHAPTERS_MODEL_H

#include <gtk/gtkliststore.h>
#include <gucharmap/gucharmap-codepoint-list.h>

G_BEGIN_DECLS

#define GUCHARMAP_TYPE_CHAPTERS_MODEL (gucharmap_chapters_model_get_type ())

#define GUCHARMAP_CHAPTERS_MODEL(obj) \
            (G_TYPE_CHECK_INSTANCE_CAST ((obj), gucharmap_chapters_model_get_type (), GucharmapChaptersModel))

#define GUCHARMAP_CHAPTERS_MODEL_CLASS(clazz) \
            (G_TYPE_CHECK_CLASS_CAST ((clazz), gucharmap_chapters_model_get_type (), GucharmapChaptersModelClass))

#define IS_GUCHARMAP_CHAPTERS_MODEL(obj) \
            (G_TYPE_CHECK_INSTANCE_TYPE ((obj), gucharmap_chapters_model_get_type ()))

#define GUCHARMAP_CHAPTERS_MODEL_GET_CLASS(obj) \
            (G_TYPE_INSTANCE_GET_CLASS ((obj), gucharmap_chapters_model_get_type (), GucharmapChaptersModelClass))

typedef struct _GucharmapChaptersModel GucharmapChaptersModel;
typedef struct _GucharmapChaptersModelClass GucharmapChaptersModelClass;

typedef enum
{
  CHAPTERS_SCRIPT = 0,
  CHAPTERS_BLOCK  = 1
}
ChaptersMode;

enum {
  CHAPTERS_ID_COL    = 0,
  CHAPTERS_LABEL_COL = 1
};

struct _GucharmapChaptersModel
{
  GtkListStore parent_instance;

  /*< protected >*/
  GucharmapCodepointList *book_list;
};

struct _GucharmapChaptersModelClass
{
  GtkListStoreClass parent_class;

  const char *title;
  gboolean (* character_to_iter) (GucharmapChaptersModel *chapters,
                                  gunichar wc,
                                  GtkTreeIter *iter);
  GucharmapCodepointList * (* get_codepoint_list) (GucharmapChaptersModel *chapters,
                                                   GtkTreeIter *iter);
  G_CONST_RETURN GucharmapCodepointList * (* get_book_codepoint_list) (GucharmapChaptersModel *chapters);
};

GType                                   gucharmap_chapters_model_get_type                (void);
GucharmapCodepointList *                gucharmap_chapters_model_get_codepoint_list      (GucharmapChaptersModel *chapters,
                                                                                          GtkTreeIter            *iter);
const char *                            gucharmap_chapters_model_get_title               (GucharmapChaptersModel *chapters);
G_CONST_RETURN GucharmapCodepointList * gucharmap_chapters_model_get_book_codepoint_list (GucharmapChaptersModel *chapters);
gboolean                                gucharmap_chapters_model_character_to_iter       (GucharmapChaptersModel *chapters,
                                                                                          gunichar                wc,
                                                                                          GtkTreeIter            *iter);
gboolean                                gucharmap_chapters_model_id_to_iter              (GucharmapChaptersModel *model,
                                                                                          const char             *id,
                                                                                          GtkTreeIter            *iter);

G_END_DECLS

#endif /* #ifndef GUCHARMAP_CHAPTERS_MODEL_H */