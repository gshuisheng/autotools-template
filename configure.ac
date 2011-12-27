# configure.ac -- autoconf file
#
#       ╔════════════════════════════════╗
#       ║ This file uses UTF-8 encoding. ║
#       ╚════════════════════════════════╝
#
# Copyright © 2011, Gregory ROMÉ
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#     * Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above copyright
#       notice, this list of conditions and the following disclaimer in the
#       documentation and/or other materials provided with the distribution.
#     * Neither the name of the Gregory ROMÉ nor the
#       names of its contributors may be used to endorse or promote products
#       derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY GREGORY ROMÉ ''AS IS'' AND ANY
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL GREGORY ROMÉ LIABLE FOR ANY
# DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
# ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

AC_PREREQ(2.59)

define([version], [1.0.0])

AC_INIT([template], [version])

AC_CONFIG_AUX_DIR([config])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES(Makefile src/Makefile libhello/Makefile)

AC_CANONICAL_SYSTEM
# 'foreign'; it's not a pure GNU project
AM_INIT_AUTOMAKE([foreign])
LT_INIT()

AC_PROG_LIBTOOL
AC_PROG_CC


# ------------------------------------------------------------------------------
# Check available libraries
#
# 
# Check that libcunit is available; define HAVE_LIBCUNIT
AC_CHECK_LIB([cunit], [CU_initialize_registry])

# ------------------------------------------------------------------------------
# Manage Revision Number
#
# Git
AC_PATH_PROG(git_cmd, git)

GIT_REVISION=`cd $(pwd)/$srcdir && git describe --all --dirty 2>/dev/null| tr -d '\n'`

if test "X$git_cmd" = "X" || 
	test "X$GIT_REVISION" = "X"
then
	git_revision="cat $(pwd)/$srcdir/GIT_REVISION"
else
	git_revision="cd $(pwd)/$srcdir && git describe --all --dirty 2>/dev/null| tr -d '\n'"
fi

AM_CONDITIONAL(HAVE_GIT_WC, \
	test "X$GIT_REVISION" != "X" || test -f $srcdir/GIT_REVISION)

AC_SUBST(git_revision)

if test "X$GIT_REVISION" != "X" || test -f $srcdir/GIT_REVISION
then
	AC_DEFINE_UNQUOTED(HAVE_VCS_REVISION_H, 1, [Have vcs_revision.h])
fi

# ------------------------------------------------------------------------------	
# libhello configuration
AC_SUBST([LIBHELLO_LT_VERSION], [0:0:0])
AC_SUBST([LIBHELLO_LT_RELEASE], [version])

AC_OUTPUT

