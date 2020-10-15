package converter

func CToF(c Celsius) Fahrenheit {
	return Fahrenheit(c*9/5 + 32)
}

func FToC(f Fahrenheit) Celsius {
	return Celsius((f - 32) * 5 / 9)
}

func CToK(c Celsius) Kelvin {
	return Kelvin(float64(c) - float64(AbsoluteZeroC))
}

func KToC(k Kelvin) Celsius {
	return Celsius(float64(k) + float64(AbsoluteZeroC))
}

func KToF(k Kelvin) Fahrenheit {
	return CToF(KToC(k))
}

func FToK(f Fahrenheit) Kelvin {
	return CToK(FToC(f))
}
