#include "ostream"
#include "Vector.hpp"

// needed to get Catch working with MinGW
#define TWOBLUECUBES_CATCH_REPORTER_JUNIT_HPP_INCLUDED
namespace Catch{ class JunitReporter{ ~JunitReporter(); }; };

#include "catch_with_main.hpp"

TEST_CASE( "Multiply two vectors" ){
   vector a( 2, 4 ), b( 1, 2 );
   a = a + b;
   REQUIRE( a == vector( 3, 6 ) );  
}

TEST_CASE( "Add a vector to another vector" ){
   vector a( 2, 4 );
   a += vector( 1, 2 );
   REQUIRE( a == vector( 3, 6 ) );  
}

TEST_CASE( "multiply by vector" ){
   vector v( 3, 4 ), x( 7, 7 );
   vector y = v * x;
   REQUIRE( y == vector( 21, 28 ) );   
}

TEST_CASE( "multiply a vector to another vector" ){
   vector x( 3, 4 ), y( 7, 7 );
   x *= y;
   REQUIRE( x == vector( 21, 28 ) );   
}






