//  tag.cpp -- predefined self-documenting option categories
//  Copyright (C) 2012  SEIKO EPSON CORPORATION
//
//  License: GPL-3.0+
//  Author : AVASYS CORPORATION
//
//  This file is part of the 'Utsushi' package.
//  This package is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License or, at
//  your option, any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//  You ought to have received a copy of the GNU General Public License
//  along with this package.  If not, see <http://www.gnu.org/licenses/>.

//  Automatically generated from tag.xml using tag.xsl.

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "utsushi/i18n.hpp"
#include "utsushi/tag.hpp"

namespace utsushi {

tag::symbol::symbol (const key& key,
                     const string& name, const string& text)
  : key_(key), name_(name), text_(text)
{}

const string&
tag::symbol::name () const
{
  return name_;
}

const string&
tag::symbol::text () const
{
  return text_;
}

bool
tag::symbol::operator== (const symbol& ts) const
{
  return key_ == ts.key_;
}

bool
tag::symbol::operator< (const tag::symbol& ts) const
{
  return key_ < ts.key_;
}

tag::symbol::operator key () const
{
  return key_;
}


const tag::symbol tag::application (
  "01_application",
  "%1%",
  N_("Options provided by %1%.")
);
const tag::symbol tag::general (
  "02_general",
  N_("General"),
  N_("Basic options.")
);
const tag::symbol tag::geometry (
  "03_geometry",
  N_("Geometry"),
  N_("Scan area and image size related options.")
);
const tag::symbol tag::enhancement (
  "04_enhancement",
  N_("Enhancement"),
  N_("Image modification options.")
);

tags::container_type tags::set_;

void
tags::initialize ()
{
  container_type::iterator hint = set_.begin ();

  hint = set_.insert (hint, tag::application);
  hint = set_.insert (hint, tag::general);
  hint = set_.insert (hint, tag::geometry);
  hint = set_.insert (hint, tag::enhancement);
}

tags::size_type
tags::count ()
{
  if (set_.empty ())
    {
      initialize ();
    }
  return set_.size ();
}

tags::const_iterator
tags::begin ()
{
  if (set_.empty ())
    {
      initialize ();
    }
  return set_.begin ();
}

tags::const_iterator
tags::end ()
{
  if (set_.empty ())
    {
      initialize ();
    }
  return set_.end ();
}

}       // namespace utsushi
