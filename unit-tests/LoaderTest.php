<?php

class LoaderTest extends PHPUnit\Framework\TestCase
{
	public function testBasic()
	{
		$loader = new \Phalcon\Loader;
		$parents = class_parents($loader);
		$this->assertEquals($parents, ['Phalcon\Injectable' => 'Phalcon\Injectable']);
		$this->assertTrue(is_object($loader));
		$this->assertTrue(method_exists($loader, 'getEventsManager'));
		$this->assertTrue(method_exists($loader, 'register'));
	}
}
