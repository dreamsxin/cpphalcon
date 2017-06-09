<?php

class VersionTest extends PHPUnit\Framework\TestCase
{
	public function testBasic()
	{
		$ver = \Phalcon\Version::get();
		$this->assertTrue(!empty($ver));

		$ver = \Phalcon\Version::getId();
		$this->assertTrue(is_numeric($ver));
	}
}
