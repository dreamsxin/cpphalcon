<?php

class DebugTest extends PHPUnit\Framework\TestCase
{
	public function testBasic()
	{
		$debug = new \Phalcon\Debug;
		$this->assertTrue(is_object($debug));
		$this->assertTrue(method_exists($debug, 'setUri'));
	}
}
