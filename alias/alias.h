/**
 * @file
 * Representation of a single alias to an email address
 *
 * @authors
 * Copyright (C) 2017 Richard Russon <rich@flatcap.org>
 * Copyright (C) 2019 Pietro Cerutti <gahr@gahr.ch>
 *
 * @copyright
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MUTT_ALIAS_ALIAS_H
#define MUTT_ALIAS_ALIAS_H

#include "mutt/lib.h"
#include "address/lib.h"

/**
 * struct Alias - A shortcut for an email address or addresses
 */
struct Alias
{
  char *name;                 ///< Short name
  struct AddressList addr;    ///< List of Addresses the Alias expands to
  char *comment;              ///< Free-form comment string
  TAILQ_ENTRY(Alias) entries; ///< Linked list
};
TAILQ_HEAD(AliasList, Alias);

extern struct AliasList Aliases;

/**
 * enum NotifyAlias - Alias notification types
 */
enum NotifyAlias
{
  NT_ALIAS_NEW = 1, ///< A new Alias has been created
  NT_ALIAS_CHANGED, ///< An Alias has been changed
  NT_ALIAS_DELETED, ///< An Alias is about to be deleted
};

/**
 * struct EventAlias - An alias-change event
 *
 * Events such as #NT_ALIAS_NEW
 */
struct EventAlias
{
  struct Alias *alias;
};

void          alias_free    (struct Alias **ptr);
void          aliaslist_free(struct AliasList *al);
struct Alias *alias_new     (void);

#endif /* MUTT_ALIAS_ALIAS_H */
