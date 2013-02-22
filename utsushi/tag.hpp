//  tag.hpp -- predefined self-documenting option categories
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

//  Automatically generated from lib/tag.xml using lib/tag.xsl.

#ifndef utsushi_tag_hpp_
#define utsushi_tag_hpp_

#include <set>

#include <boost/operators.hpp>

#include "key.hpp"
#include "string.hpp"

namespace utsushi {

struct tag
{
  //! Collect options and groups by the aspects they affect
  /*! A %tag::symbol is a string-like key that can be used to indicate
   *  which aspects are affected by an option or group.  An option may
   *  specify zero or more %tag symbols.
   *
   *  Similar to a descriptor, every %tag::symbol provides name() and
   *  text() accessors describing its purpose.  A user interface may
   *  use this information to provide a more human-oriented and mostly
   *  self-documenting view of tags.
   *
   *  \note  The UI is responsible for the translation of name() and
   *         text() as well as any formatting of the text().
   *
   *  \sa  descriptor::name(), descriptor::text()
   */
  class symbol
    : boost::totally_ordered< symbol >
  {
  public:
    symbol (const key& key,
            const string& name, const string& text);

    //! \copybrief descriptor::name
    const string& name () const;
    //! \copybrief descriptor::text
    const string& text () const;

    bool operator== (const symbol& ts) const;
    bool operator< (const symbol& ts) const;

    operator key () const;

  private:
    key key_;
    string name_;
    string text_;
  };

  static const symbol none;
  static const symbol application;
  static const symbol general;
  static const symbol geometry;
  static const symbol enhancement;
};

class tags
{
private:
  typedef std::set< tag::symbol > container_type;
  static container_type set_;
  static void initialize ();

public:
  typedef container_type::size_type size_type;
  typedef container_type::const_iterator const_iterator;

  static size_type count ();
  static const_iterator begin ();
  static const_iterator end ();
};

}       // namespace utsushi

#endif  /* utsushi_tag_hpp_ */
