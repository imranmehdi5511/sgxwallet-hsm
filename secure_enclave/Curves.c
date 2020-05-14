/*
    Copyright (C) 2019-Present SKALE Labs

    This file is part of sgxwallet.

    sgxwallet is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    sgxwallet is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with sgxwallet.  If not, see <https://www.gnu.org/licenses/>.

    @file curves.c
    @author Stan Kladko
    @date 2019
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifdef NO_SGX
#include <gmp.h>
#else
#include <../tgmp-build/include/sgx_tgmp.h>
#endif

#include "DomainParameters.h"
#include "Curves.h"
#include "Point.h"

/*Load a curve depending on it's curve number, defined by the enum*/
void domain_parameters_load_curve(domain_parameters out, curve_list curve)
{
	switch(curve)
	{
case secp112r1:
	domain_parameters_set_hex(out, "secp112r1",
										"DB7C2ABF62E35E668076BEAD208B",
										"DB7C2ABF62E35E668076BEAD2088",
										"659EF8BA043916EEDE8911702B22",
										"09487239995A5EE76B55F9C2F098",
										"A89CE5AF8724C0A23E0E0FF77500",
										"DB7C2ABF62E35E7628DFAC6561C5",
										"01");
	break;
//See remark in curves.h
/*case secp112r2:
	domain_parameters_set_hex(out, "secp112r2",
										"DB7C2ABF62E35E668076BEAD208B",
										"6127C24C05F38A0AAAF65C0EF02C",
										"51DEF1815DB5ED74FCC34C85D709",
										"4BA30AB5E892B4E1649DD0928643",
										"ADCD46F5882E3747DEF36E956E97",
										"36DF0AAFD8B8D7597CA10520D04B",
										"04");
*/
	break;
case secp128r1:
	domain_parameters_set_hex(out, "secp128r1",
										"FFFFFFFDFFFFFFFFFFFFFFFFFFFFFFFF",
										"FFFFFFFDFFFFFFFFFFFFFFFFFFFFFFFC",
										"E87579C11079F43DD824993C2CEE5ED3",
										"161FF7528B899B2D0C28607CA52C5B86",
										"CF5AC8395BAFEB13C02DA292DDED7A83",
										"FFFFFFFE0000000075A30D1B9038A115",
										"01");
	break;
//See remark in curves.h
/*case secp128r2:
	domain_parameters_set_hex(out, "secp128r2",
										"FFFFFFFDFFFFFFFFFFFFFFFFFFFFFFFF",
										"D6031998D1B3BBFEBF59CC9BBFF9AEE1",
										"5EEEFCA380D02919DC2C6558BB6D8A5D",
										"7B6AA5D85E572983E6FB32A7CDEBC140",
										"27B6916A894D3AEE7106FE805FC34B44",
										"3FFFFFFF7FFFFFFFBE0024720613B5A3",
										"04");
*/
	break;
case secp160k1:
	domain_parameters_set_hex(out, "secp160k1",
										"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFAC73",
										"0000000000000000000000000000000000000000",
										"0000000000000000000000000000000000000007",
										"3B4C382CE37AA192A4019E763036F4F5DD4D7EBB",
										"938CF935318FDCED6BC28286531733C3F03C4FEE",
										"0100000000000000000001B8FA16DFAB9ACA16B6B3",
										"01");
	break;
case secp160r1:
	domain_parameters_set_hex(out, "secp160r1",
										"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7FFFFFFF",
										"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7FFFFFFC",
										"1C97BEFC54BD7A8B65ACF89F81D4D4ADC565FA45",
										"4A96B5688EF573284664698968C38BB913CBFC82",
										"23A628553168947D59DCC912042351377AC5FB32",
										"0100000000000000000001F4C8F927AED3CA752257",
										"01");
	break;
case secp160r2:
	domain_parameters_set_hex(out, "secp160r2",
										"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFAC73",
										"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFAC70",
										"B4E134D3FB59EB8BAB57274904664D5AF50388BA",
										"52DCB034293A117E1F4FF11B30F7199D3144CE6D",
										"FEAFFEF2E331F296E071FA0DF9982CFEA7D43F2E",
										"0100000000000000000000351EE786A818F3A1A16B",
										"01");
	break;
case secp192k1:
	domain_parameters_set_hex(out, "secp192k1",
										"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFEE37",
										"000000000000000000000000000000000000000000000000",
										"000000000000000000000000000000000000000000000003",
										"DB4FF10EC057E9AE26B07D0280B7F4341DA5D1B1EAE06C7D",
										"9B2F2F6D9C5628A7844163D015BE86344082AA88D95E2F9D",
										"FFFFFFFFFFFFFFFFFFFFFFFE26F2FC170F69466A74DEFD8D",
										"01");
	break;
case secp192r1:
	domain_parameters_set_hex(out, "secp192r1",
										"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFFFFFFFFFFFF",
										"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFFFFFFFFFFFC",
										"64210519E59C80E70FA7E9AB72243049FEB8DEECC146B9B1",
										"188DA80EB03090F67CBF20EB43A18800F4FF0AFD82FF1012",
										"07192B95FFC8DA78631011ED6B24CDD573F977A11E794811",
										"FFFFFFFFFFFFFFFFFFFFFFFF99DEF836146BC9B1B4D22831",
										"01");
	break;
case secp224k1:
	domain_parameters_set_hex(out, "secp224k1",
										"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFE56D",
										"00000000000000000000000000000000000000000000000000000000",
										"00000000000000000000000000000000000000000000000000000005",
										"A1455B334DF099DF30FC28A169A467E9E47075A90F7E650EB6B7A45C",
										"7E089FED7FBA344282CAFBD6F7E319F7C0B0BD59E2CA4BDB556D61A5",
										"010000000000000000000000000001DCE8D2EC6184CAF0A971769FB1F7",
										"01");
	break;
case secp224r1:
	domain_parameters_set_hex(out, "secp224r1",
										"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000001",
										"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFE",
										"B4050A850C04B3ABF54132565044B0B7D7BFD8BA270B39432355FFB4",
										"B70E0CBD6BB4BF7F321390B94A03C1D356C21122343280D6115C1D21",
										"BD376388B5F723FB4C22DFE6CD4375A05A07476444D5819985007E34",
										"FFFFFFFFFFFFFFFFFFFFFFFFFFFF16A2E0B8F03E13DD29455C5C2A3D",
										"01");
	break;
case secp256k1:
	domain_parameters_set_hex(out, "secp256k1",
										"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFC2F",
										"0000000000000000000000000000000000000000000000000000000000000000",
										"0000000000000000000000000000000000000000000000000000000000000007",
										"79BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798",
										"483ADA7726A3C4655DA4FBFC0E1108A8FD17B448A68554199C47D08FFB10D4B8",
										"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBAAEDCE6AF48A03BBFD25E8CD0364141",
										"01");
	break;
case secp256r1:
	domain_parameters_set_hex(out, "secp256r1",
										"FFFFFFFF00000001000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFF",
										"FFFFFFFF00000001000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFC",
										"5AC635D8AA3A93E7B3EBBD55769886BC651D06B0CC53B0F63BCE3C3E27D2604B",
										"6B17D1F2E12C4247F8BCE6E563A440F277037D812DEB33A0F4A13945D898C296",
										"4FE342E2FE1A7F9B8EE7EB4A7C0F9E162BCE33576B315ECECBB6406837BF51F5",
										"FFFFFFFF00000000FFFFFFFFFFFFFFFFBCE6FAADA7179E84F3B9CAC2FC632551",
										"01");
	break;
case secp384r1:
	domain_parameters_set_hex(out, "secp384r1",
									"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFFFF0000000000000000FFFFFFFF",
									"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFFFF0000000000000000FFFFFFFC",
									"B3312FA7E23EE7E4988E056BE3F82D19181D9C6EFE8141120314088F5013875AC656398D8A2ED19D2A85C8EDD3EC2AEF",
									"AA87CA22BE8B05378EB1C71EF320AD746E1D3B628BA79B9859F741E082542A385502F25DBF55296C3A545E3872760AB7",
									"3617DE4A96262C6F5D9E98BF9292DC29F8F41DBD289A147CE9DA3113B5F0B8C00A60B1CE1D7E819D7A431D7C90EA0E5F",
									"FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC7634D81F4372DDF581A0DB248B0A77AECEC196ACCC52973",
									"01");
	break;
case secp521r1:
	domain_parameters_set_hex(out, "secp521r1",
"01FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF",
"01FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC",
"0051953EB9618E1C9A1F929A21A0B68540EEA2DA725B99B315F3B8B489918EF109E156193951EC7E937B1652C0BD3BB1BF073573DF883D2C34F1EF451FD46B503F00",
"00C6858E06B70404E9CD9E3ECB662395B4429C648139053FB521F828AF606B4D3DBAA14B5E77EFE75928FE1DC127A2FFA8DE3348B3C1856A429BF97E7E31C2E5BD66",
"011839296A789A3BC0045C8A5FB42C7D1BD998F54449579B446817AFBD17273E662C97EE72995EF42640C550B9013FAD0761353C7086A272C24088BE94769FD16650",
"01FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA51868783BF2F966B7FCC0148F709A5D03BB5C9B8899C47AEBB6FB71E91386409",
									"01");
	break;
default:
    break;
	//Write error message
	//fprintf(stderr, "\nCurve number not available!\n");
	//exit(4);	//Exit with 4, internal inconsistency
	}
}
