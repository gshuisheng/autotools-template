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

# ==============================================================================
# Autoconf Layout
#
# 1.  Autoconf requirements
# 2.  AC_INIT(package, version, bug-report-address)
# 3.  information on the package
# 4.  checks for programs
# 5.  checks for libraries
# 6.  checks for header files
# 7.  checks for types
# 8.  checks for structures
# 9.  checks for compiler characteristics
# 10. checks for library functions
# 11. checks for system services
# 12. AC_CONFIG_FILES([file...])
# 13. AC_OUTPUT

# ==============================================================================
# 1. Autoconf requirements
AC_PREREQ(2.59)

# ==============================================================================
# 2. AC_INIT(package, version, bug-report-address)
define([version], [1.0.0]) # For sharing the version number
AC_INIT([template], [version], [gregory.rome@gmail.com])

# ==============================================================================
# 3. information on the package
AC_CONFIG_AUX_DIR([config])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])

AC_CANONICAL_SYSTEM

AM_INIT_AUTOMAKE([foreign]) # 'foreign' => not a pure GNU project
LT_INIT

# ------------------------------------------------------------------------------
# Options

# Enable debug
# Debug options are defined in Makefile.am
AC_ARG_WITH([debug], [AS_HELP_STRING([--with-debug],
	[Enable debug (default is no)])], [enable_debug=$withval],
	[enable_debug=no])
	
AM_CONDITIONAL(ENABLE_DEBUG, test "X$enable_debug" = "Xyes")

# Enable coverage
AC_ARG_WITH([coverage], [AS_HELP_STRING([--with-coverage],
	[Enable coverage (default is no)])], [enable_coverage=$withval],
	[enable_coverage=no])

AM_CONDITIONAL(ENABLE_COVERAGE, test "X$enable_coverage" = "Xyes")
if test "X$enable_coverage" = "Xyes"
then
	CFLAGS="$CFLAGS --coverage"
	LDFLAGS="$LDFLAGS -lgcov"
fi

# ==============================================================================
# 4. checks for programs
AC_PATH_PROG(git_cmd, git)
AC_PATH_PROG(svnversion_cmd, svnversion)

have_git_revision=false
have_svn_revision=false

# --------------------------
# Have svn or git revision ?
if test "X$git_cmd" != "X"
then
	GIT_REVISION=`cd $(pwd)/$srcdir && $git_cmd describe --all --dirty 2>/dev/null| tr -d '\n'`
fi

if test "X$GIT_REVISION" != "X" || test -f $srcdir/GIT_REVISION
then
	have_git_revision=true
else
	if test "X$svnversion_cmd" != "X"
	then
		SVN_REVISION=`svnversion $(pwd)/$srcdir`
	fi
fi

if test "X$SVN_REVISION" != "Xexported" || test -f $srcdir/SVN_REVISION
then
	have_svn_revision=true
fi

AM_CONDITIONAL(HAVE_GIT_WC, test "X$have_git_revision" = "Xtrue")
AM_CONDITIONAL(HAVE_SVN_WC, test "X$have_svn_revision" = "Xtrue")

# ---------------------------
# Define command vcs_revision
if test "X$have_git_revision" = "Xtrue"
then
	if test "X$GIT_REVISION" = "X"
	then
		vcs_revision="cat $(pwd)/$srcdir/GIT_REVISION"
	else
		vcs_revision="cd $(pwd)/$srcdir && git describe --all --dirty 2>/dev/null| tr -d '\n'"
	fi
	VCS_FILE=GIT_REVISION
elif test "X$have_svn_revision" = "Xtrue"
then
	if test "X$SVN_REVISION" = "X"
	then
		vcs_revision="cat $(pwd)/$srcdir/SVN_REVISION"
	else
		vcs_revision="svnversion $(pwd)/$srcdir"
	fi
	VCS_FILE=SVN_REVISION
fi

AC_SUBST(vcs_revision)
AC_SUBST(VCS_FILE)

if test "X$have_git_revision" = "Xtrue" || "X$have_svn_revision" = "Xtrue"
then
	AC_DEFINE_UNQUOTED(HAVE_VCS_REVISION_H, 1, [Have vcs_revision.h])
fi

# ==============================================================================
# 5.  checks for libraries
AC_CHECK_LIB([cunit], [CU_initialize_registry]) # libcunit for testing

# ==============================================================================
# 6.  checks for header files
# ==============================================================================
# 7.  checks for types
# ==============================================================================
# 8.  checks for structures
# ==============================================================================
# 9.  checks for compiler characteristics
AC_PROG_CC
AC_PROG_LIBTOOL

# ==============================================================================
# 10. checks for library functions
# ==============================================================================
# 11. checks for system services
# ==============================================================================
# 12. AC_CONFIG_FILES([file...])
AC_CONFIG_FILES(Makefile src/Makefile)

# ==============================================================================
AC_OUTPUT

