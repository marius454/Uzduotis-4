# Uzduotis-4

## "Cool dalykėliai"

1. Kai Visual Studio kompiliatorius automatiskai didina capacity, kitaip nei kiti kompiliatoriai, jis capacity padidina 1,5 karto, o ne 2 kartus. Taip sutaupo naudojamos vietos bet praranda spartos.

2. realloc

```c++
template <typename T>
T* Vector<T>::insert(T* pos, T&& val)
{
	size_t x = std::distance(&elem[0], pos);
	if (sz == cp) {
		cp = cp * 2;
		elem = (T*)realloc(elem, cp * sizeof(T));
	}
	for (size_t i = sz - 1; i >= x; --i) {
		elem[i + 1] = elem[i];
		if (i == 0) break;
	}
	elem[x] = std::move(val);
	++sz;
	return pos;
}
```








## Užduoties aprašymas:

  Sukurti savo Vector implementaciją ir palyginti ją su std::vector. Mano Vector gali naudoti tik bazinius tipus.

## Mano Vector vs std::vector:

Default:

|elementu skaicius                |Mano Vector       |std::vector     |
|---------------------------------|------------------|----------------|
|10000|7.04282e-05s|0.0011462s|
|100000|0.000725902s|0.01140048s|
|1000000|0.00809289s|0.1134s|
|10000000|0.104117s|1.15464s|
|100000000|0.925328s|11.6216s|

**Disclamer:** toks didelis skirtumas gali būti dėl "Visual Studio" kompiliatoriaus

Naudojant O1 optimizacijos flag'a:

|elementu skaicius                |Mano Vector       |std::vector     |
|---------------------------------|------------------|----------------|
|10000|4.8014e-05s|0.0003788311s|
|100000|0.000502214s|0.00343188s|
|1000000|0.00582564s|0.0342553s|
|10000000|0.0822436s|0.361237s|
|100000000|0.700845s|3.70729s|

Naudojant O2 optimizacijos flag'a:

|elementu skaicius                |Mano Vector       |std::vector     |
|---------------------------------|------------------|----------------|
|10000|2.86718e-05s|0.000306745s|
|100000|0.000309475s|0.00302614s|
|1000000|0.00398131s|0.0303935s|
|10000000|0.0634495s|0.323148s|
|100000000|0.509963s|3.34174s|

Naudojant Ox optimizacijos flag'a:

|elementu skaicius                |Mano Vector       |std::vector     |
|---------------------------------|------------------|----------------|
|10000|2.91272e-05s|0.000305493s|
|100000|0.000316302s|0.00303263s|
|1000000|0.00400475s|0.0304131s|
|10000000|0.00638869s|0.329248s|
|100000000|0.515947|3.37797s|
