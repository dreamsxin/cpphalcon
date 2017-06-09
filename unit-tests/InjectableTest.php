<?php

class Test extends \Phalcon\Injectable {}

class InjectableTest extends PHPUnit\Framework\TestCase
{
	public function testBasic()
	{
		$test = new \Test;
		$this->assertTrue(is_object($test));
		$this->assertTrue(method_exists($test, 'getDI'));
		$this->assertTrue(method_exists($test, 'getEventsManager'));
	}
}
