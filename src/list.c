/*
 *  list.c -- list structures
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "list.h"

int
list_insert(list_node_t **queue, list_node_t *node, int (*order)(void *, void *))
{
  list_node_t *p, *q;

  if (!queue || !node)
    return 0;

  /* set queue head if empty */
  if (!*queue) {
    *queue = node;
    return 1;
  }

  q = *queue;
  if (order) {
    /* replace queue head if new node has to be inserted before existing head */
    if (order(node->data, q->data) < 0) {
      node->next = q;
      *queue = node;
      return 1;
    }

    /* search for right place to insert */
    do {
      p = q;
      q = q->next;
    } while (q && order(node->data, q->data) >= 0);
  } else {
    /* find the end */
    do {
      p = q;
      q = q->next;
    } while (q);
  }

  /* insert new node */
  node->next = q;
  p->next = node;
  return 1;
}

list_node_t *
list_remove(list_node_t **queue, list_node_t *node, int (*compare)(void *, void *))
{
  return node ? list_remove_data(queue, node->data, compare) : NULL;
}

list_node_t *
list_remove_data(list_node_t **queue, void *data, int (*compare)(void *, void *))
{
  list_node_t *p, *q;

  if (!queue)
    return NULL;

  p = NULL;
  q = *queue;
  while (q && compare(data, q->data) != 0) {
    p = q;
    q = q->next;
  }

  if (q) {
    if (NULL == p)
      *queue = q->next;
    else {
      p->next = q->next;
      q->next = NULL;
      return q;
    }
  }

  return NULL;
}

int
list_delete_node(list_node_t *node)
{
  if (!node)
    return 0;
  //free(node->data);
  free(node);
  return 1;
}

void
list_delete_all(list_node_t *queue)
{
  if (!queue)
    return;
  list_delete_all(queue->next);
  list_delete_node(queue);
}

list_node_t *
list_new_node(void *data)
{
  list_node_t *node = (list_node_t *) malloc(sizeof(list_node_t));
  if (!node) {
    return NULL;
  }
  memset(node, 0, sizeof(list_node_t));
  node->data = data;
  return node;
}
