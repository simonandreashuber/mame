# Modular Arithmetic with Multiple Exponents

### about
In [this repository](https://github.com/simonandreashuber/mame) you can find the tools to do modular arithmetics for numbers written with multible exponents, where it would be infeasible to calculate the result with conventional methods.

### usage

```C++
//create:
ime reileen({2,3,7}); //2^3^7

//calculate:
reileen % 1999;
reileen.mod(1999);
```

## License & Copyright
This Project is licensed under the [MIT License](LICENSE).
