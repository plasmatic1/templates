using ll = long long;
using ull = unsigned long long;
ull multiplyHighUnsigned(ull x, ull y) {
    ull x_high = x >> 32;
    ull y_high = y >> 32;
    ull x_low = x & 0xFFFFFFFFL;
    ull y_low = y & 0xFFFFFFFFL;
        
    ull z2 = x_low * y_low;
    ull t = x_high * y_low + (z2 >> 32);
    ull z1 = t & 0xFFFFFFFFL;
    ull z0 = t >> 32;
    z1 += x_low * y_high;
    return x_high * y_high + z0 + (z1 >> 32);
}
ll mulMod(a: Long, b: Long {
    xh = multiplyHighUnsigned(a, b) // high word of product
    xl = a * b // low word of product

    xrh = multiplyHighUnsigned(xh, BARR_R) // high word of xr
    xrm = multiplyHighUnsigned(xl, BARR_R) // middle word of xr, first part
    add = xh * BARR_R // second part of middle word
    xrm += add // add them
    if(add ^ (1L << 63) > xrm ^ (1L << 63)) xrh++ // carry, see note 1

    t = xl - ((xrh << 2) | (xrm >>> 62)) * MOD - MOD // see note 2
    t += (t >> 63) & MOD
    return t
}
