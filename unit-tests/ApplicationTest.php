<?php

class ApplicationTest extends PHPUnit\Framework\TestCase
{
	public function testBasic()
	{
		$abstractClass = new ReflectionClass('Phalcon\Application');
		$this->assertTrue($abstractClass->isAbstract());
		$this->assertTrue(method_exists('Phalcon\Application' , 'registerModules'));
		$this->assertTrue(method_exists('Phalcon\Application' , 'getModules'));
		$this->assertTrue(method_exists('Phalcon\Application' , 'setDefaultModule'));
		$this->assertTrue(method_exists('Phalcon\Application' , 'getDefaultModule'));
	}
}
