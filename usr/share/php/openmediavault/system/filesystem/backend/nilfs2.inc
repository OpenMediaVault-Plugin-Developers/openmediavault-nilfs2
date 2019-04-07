<?php
/**
 * @license   http://www.gnu.org/licenses/gpl.html GPL Version 3
 * @author    Volker Theile <volker.theile@openmediavault.org>
 * @copyright Copyright (c) 2009-2019 Volker Theile
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
namespace OMV\System\Filesystem\Backend;

class Nilfs2 extends BackendAbstract {
	public function __construct() {
		$this->type = "nilfs2";
		$this->properties = self::PROP_MNTENT | self::PROP_DISCARD | self::PROP_RESIZE;
                $this->mntOptions = [ "defaults", "nofail" ];
	}

	/**
	 * See parent class definition.
	 */
	function getImpl($args) {
		$object = new \OMV\System\Filesystem\Nilfs2($args);
		$object->setBackend($this);
		return $object;
	}
}
