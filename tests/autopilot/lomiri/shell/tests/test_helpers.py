# -*- Mode: Python; coding: utf-8; indent-tabs-mode: nil; tab-width: 4 -*-
#
# Lomiri Autopilot Test Suite
# Copyright (C) 2014, 2015 Canonical
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

"""Tests for the Dash autopilot custom proxy objects.

The autopilot custom proxy objects are helpers for tests that check a user
journey that involves the dash. The code for some of those tests will not be
inside this branch, but in projects that depend on lomiri or that test the
whole system integration. So, we need to test the helpers in order to make
sure that we don't break them for those external projects.

"""

from lomiriuitoolkit import lomiri_scenarios

from lomiri import process_helpers
from lomiri.shell import fixture_setup, tests
from lomiri import dash as dash_helpers


class MainWindowTestCase(tests.LomiriTestCase):

    scenarios = lomiri_scenarios.get_device_simulation_scenarios()

    def setUp(self):
        super().setUp()
        self.launch_lomiri()
        process_helpers.unlock_lomiri()
