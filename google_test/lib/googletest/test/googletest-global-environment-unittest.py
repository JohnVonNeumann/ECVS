# Copyright 2021 Google Inc. All Rights Reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
#     * Redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above
# copyright notice, this list of conditions and the following disclaimer
# in the documentation and/or other materials provided with the
# distribution.
#     * Neither the name of Google Inc. nor the names of its
# contributors may be used to endorse or promote products derived from
# this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
"""Unit test for Google Test's global test environment behavior.

A user can specify a global test environment via
testing::AddGlobalTestEnvironment. Failures in the global environment should
result in all unit tests being skipped.

This script tests such functionality by invoking
lib-global-environment-unittest_ (a program written with Google Test).
"""

import gtest_test_utils


def RunAndReturnOutput():
  """Runs the test program and returns its output."""

  return gtest_test_utils.Subprocess([
      gtest_test_utils.GetTestExecutablePath(
          'lib-global-environment-unittest_')
  ]).output


class GTestGlobalEnvironmentUnitTest(gtest_test_utils.TestCase):
  """Tests global test environment failures."""

  def testEnvironmentSetUpFails(self):
    """Tests the behavior of not specifying the fail_fast."""

    # Run the test.
    txt = RunAndReturnOutput()

    # We should see the text of the global environment setup error.
    self.assertIn('Canned environment setup error', txt)

    # Our test should have been skipped due to the error, and not treated as a
    # pass.
    self.assertIn('[  SKIPPED ] 1 test', txt)
    self.assertIn('[  PASSED  ] 0 tests', txt)

    # The test case shouldn't have been run.
    self.assertNotIn('Unexpected call', txt)


if __name__ == '__main__':
  gtest_test_utils.Main()