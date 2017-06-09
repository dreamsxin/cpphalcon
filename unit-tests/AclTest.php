<?php

class AclTest extends PHPUnit\Framework\TestCase
{
	public function testBasic()
	{
		$abstractClass = new ReflectionClass('Phalcon\Acl');
		$this->assertTrue($abstractClass->isAbstract());
	}
}
