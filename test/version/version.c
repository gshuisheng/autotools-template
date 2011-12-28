/*
 * version.c --
 *
 *       ╔════════════════════════════════╗
 *       ║ This file uses UTF-8 encoding. ║
 *       ╚════════════════════════════════╝
 *
 * -----------------------------------------------------------------------------
 * Copyright © 2011, Gregory ROMÉ
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Gregory ROMÉ nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY GREGORY ROMÉ ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL GREGORY ROMÉ LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * -----------------------------------------------------------------------------
 */
 
#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"

#include "version.h"

int version_test_init_suite(void)
{
	return 0;
}

int version_test_clean_suite(void)
{
	return 0;
}


void version_test_get_version(void)
{
	version_get_version();
	CU_ASSERT(0 == 0);
}

void version_test_get_revision(void)
{
	version_get_revision();
	CU_ASSERT(0 == 0);
}

int version_test_register(CU_pSuite pSuite)
{
   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_version", version_test_init_suite, version_test_clean_suite);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   if ((NULL == CU_add_test(pSuite, "version::get_version", version_test_get_version)) ||
       (NULL == CU_add_test(pSuite, "version::get_revision", version_test_get_revision)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }
}
