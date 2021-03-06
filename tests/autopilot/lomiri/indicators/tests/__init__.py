# -*- Mode: Python; coding: utf-8; indent-tabs-mode: nil; tab-width: 4 -*-
#
# Lomiri - Indicators Autopilot Test Suite
# Copyright (C) 2013, 2014, 2015 Canonical
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

from autopilot import platform
from lomiriuitoolkit import lomiri_scenarios

from lomiri import process_helpers
from lomiri.shell import tests


class IndicatorTestCase(tests.LomiriTestCase):

    device_emulation_scenarios = (
        lomiri_scenarios.get_device_simulation_scenarios())

    def setUp(self):
        super().setUp()
        self.lomiri_proxy = self.launch_lomiri()
        process_helpers.unlock_lomiri()


class DeviceIndicatorTestCase(IndicatorTestCase):

    def setUp(self):
        if platform.model() == 'Desktop':
            self.skipTest('Test cannot be run on the desktop.')
        super().setUp()
