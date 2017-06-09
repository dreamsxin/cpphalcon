<?php

class DiTest extends PHPUnit\Framework\TestCase
{
	public function testBasic()
	{
		$di = \Phalcon\Di::getDefault();
		$this->assertNull($di);

		$di = new \Phalcon\Di();
		$implements = class_implements($di);
		$this->assertEquals($implements, ['Phalcon\DiInterface' => 'Phalcon\DiInterface']);
		$this->assertTrue(is_object($di));

		$di = \Phalcon\Di::getDefault();
		$this->assertTrue(is_object($di));
	}
}
