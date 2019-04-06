<?php

namespace OMV\System\Filesystem\Backend;

$backends = [ "Nilfs2" ];
$mngr = Manager::getInstance();
foreach ($backends as $backendk => $backendv) {
	$className = sprintf("%s\%s", __NAMESPACE__, $backendv);
	$mngr->registerBackend(new $className());
}
if (TRUE === $debug)
	$mngr->dump();
