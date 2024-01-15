/*
 *  list.h -- list structures
 *  Copyright (C) 2011  Longshine <longxianghe@gmail.com>
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
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __LIST_H__
#define __LIST_H__

#define list_is_empty(queue) (NULL == queue)

typedef struct list_node_s {
  struct list_node_s *next;
  void *data;
} list_node_t;

int list_insert(list_node_t **queue, list_node_t *node, int (*order)(void *, void *));
list_node_t* list_remove(list_node_t **queue, list_node_t *node, int (*order)(void *, void *));
list_node_t* list_remove_data(list_node_t **queue, void *data, int (*order)(void *, void *));
int list_delete_node(list_node_t *node);
void list_delete_all(list_node_t *queue);
list_node_t* list_new_node(void *data);

#endif /* __LIST_H__ */
