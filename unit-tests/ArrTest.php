<?php

class ArrTest extends PHPUnit\Framework\TestCase
{
	public function testBasic()
	{
		$this->assertTrue(method_exists('Phalcon\Arr', 'is_assoc'));

		$class = new ReflectionClass('Phalcon\Arr');
		$method = $class->getMethod('is_assoc');
		$this->assertTrue($method->isStatic());
	}
}
