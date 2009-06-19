/*
 * Copyright © 2009 Codethink Limited
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of version 3 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * See the included COPYING file for more information.
 *
 * Authors: Ryan Lortie <desrt@desrt.ca>
 */

#include <dconf.h>
#include <stdio.h>

int
main (int argc, char **argv)
{
  GVariant *value;

  if (argc != 2 || !dconf_is_key (argv[1]))
    {
      fprintf (stderr, "usage: dconf-get /dconf/path\n");
      return 1;
    }

  value = dconf_get (argv[1]);

  if (value != NULL)
    {
      GString *string;

      string = g_variant_markup_print (value, NULL, TRUE, 0, 2);
      printf ("%s", string->str);
      g_string_free (string, TRUE);

      g_variant_unref (value);
    }

  return 0;
}