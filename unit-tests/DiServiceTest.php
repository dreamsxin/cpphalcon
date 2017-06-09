<?php

class DiService extends PHPUnit\Framework\TestCase
{
	public function testBasic()
	{
		$service = new \Phalcon\Di\Service('db', function(){return new stdClass;});
		$implements = class_implements($service);
		$this->assertEquals($implements, ['Phalcon\Di\ServiceInterface' => 'Phalcon\Di\ServiceInterface']);
		$this->assertTrue(is_object($service));
	}
}
