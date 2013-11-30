//  image-skip.cpp -- unit tests for the image-skip filter implementation
//  Copyright (C) 2013  SEIKO EPSON CORPORATION
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

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <boost/test/unit_test.hpp>

#include <utsushi/file.hpp>
#include <utsushi/stream.hpp>
#include <utsushi/test/memory.hpp>

#include "../image-skip.hpp"
#include "../pnm.hpp"

using namespace utsushi;
using _flt_::image_skip;
using _flt_::iimage_skip;
using _flt_::pnm;

BOOST_AUTO_TEST_CASE (skip_all_white)
{
  context ctx (100, 100, context::GRAY8);
  shared_ptr< setmem_idevice::generator > gen
    = make_shared< const_generator > (0xff);

  istream istr;
  ostream ostr;

  istr.push (make_shared< setmem_idevice > (gen, ctx, 2));
  ostr.push (make_shared< image_skip > ());
  ostr.push (make_shared< pnm > ());
  ostr.push (make_shared< file_odevice >
             (path_generator ("skip", "pnm")));

  istr | ostr;

  BOOST_CHECK (!fs::exists ("skip000.pnm"));
  if (fs::exists ("skip000.pnm")) remove ("skip000.pnm");
  BOOST_CHECK (!fs::exists ("skip001.pnm"));
  if (fs::exists ("skip001.pnm")) remove ("skip001.pnm");
}

BOOST_AUTO_TEST_CASE (keep_all_black)
{
  context ctx (100, 100, context::GRAY8);
  shared_ptr< setmem_idevice::generator > gen
    = make_shared< const_generator > (0x00);

  istream istr;
  ostream ostr;

  istr.push (make_shared< setmem_idevice > (gen, ctx, 2));
  ostr.push (make_shared< image_skip > ());
  ostr.push (make_shared< pnm > ());
  ostr.push (make_shared< file_odevice >
             (path_generator ("skip", "pnm")));

  istr | ostr;

  BOOST_CHECK (fs::exists ("skip000.pnm"));
  if (fs::exists ("skip000.pnm")) remove ("skip000.pnm");
  BOOST_CHECK (fs::exists ("skip001.pnm"));
  if (fs::exists ("skip001.pnm")) remove ("skip001.pnm");
}

BOOST_AUTO_TEST_CASE (iskip_all_white)
{
  context ctx (100, 100, context::GRAY8);
  shared_ptr< setmem_idevice::generator > gen
    = make_shared< const_generator > (0xff);

  istream istr;
  ostream ostr;

  istr.push (make_shared< iimage_skip > ());
  istr.push (make_shared< setmem_idevice > (gen, ctx, 2));
  ostr.push (make_shared< pnm > ());
  ostr.push (make_shared< file_odevice >
             (path_generator ("skip", "pnm")));

  istr | ostr;

  BOOST_CHECK (!fs::exists ("skip000.pnm"));
  if (fs::exists ("skip000.pnm")) remove ("skip000.pnm");
  BOOST_CHECK (!fs::exists ("skip001.pnm"));
  if (fs::exists ("skip001.pnm")) remove ("skip001.pnm");
}

BOOST_AUTO_TEST_CASE (ikeep_all_black)
{
  context ctx (100, 100, context::GRAY8);
  shared_ptr< setmem_idevice::generator > gen
    = make_shared< const_generator > (0x00);

  istream istr;
  ostream ostr;

  istr.push (make_shared< iimage_skip > ());
  istr.push (make_shared< setmem_idevice > (gen, ctx, 2));
  ostr.push (make_shared< pnm > ());
  ostr.push (make_shared< file_odevice >
             (path_generator ("skip", "pnm")));

  istr | ostr;

  BOOST_CHECK (fs::exists ("skip000.pnm"));
  if (fs::exists ("skip000.pnm")) remove ("skip000.pnm");
  BOOST_CHECK (fs::exists ("skip001.pnm"));
  if (fs::exists ("skip001.pnm")) remove ("skip001.pnm");
}

#include "utsushi/test/runner.ipp"
