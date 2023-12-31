#include <iosfwd>
#include <set>
#include <string>

#include "cata_catch.h"
#include "enum_traits.h"
#include "name.h"

class IsOneOf : public Catch::MatcherBase<std::string>
{
        std::set< std::string > values;
    public:
        explicit IsOneOf( const std::set< std::string > &v ): values{v} {}
        bool match( std::string const &s ) const override {
            return values.count( s ) > 0;
        }
        std::string describe() const override {
            std::string s = "is one of {";
            for( auto const &i : values ) {
                s += i + ", ";
            }
            s.back() = '}';
            return s;
        }
};

TEST_CASE( "name_generation", "[name]" )
{
    GIVEN( "Names loaded from tests/data/name.json" ) {
        Name::clear();
        Name::load_from_file( PATH_INFO::base_path_path() / "tests" / "data" / "name.json" );
        WHEN( "Getting a town name" ) {
            std::string name = Name::get( nameFlags::IsTownName );
            CHECK( name == "City" );
        }
        WHEN( "Getting a world name" ) {
            std::string name = Name::get( nameFlags::IsWorldName );
            CHECK( name == "World" );
        }
        WHEN( "Getting a nick name" ) {
            std::string name = Name::get( nameFlags::IsNickName );
            CHECK( name == "Nick" );
        }
        WHEN( "Getting a male given name" ) {
            for( int i = 0; i < 8; ++i ) {
                std::string name = Name::get( nameFlags::IsMaleName | nameFlags::IsGivenName );
                CHECK_THAT( name, IsOneOf( {"Male", "Unisex"} ) );
            }
        }
        WHEN( "Getting a female given name" ) {
            for( int i = 0; i < 8; ++i ) {
                std::string name = Name::get( nameFlags::IsFemaleName | nameFlags::IsGivenName );
                CHECK_THAT( name, IsOneOf( {"Female", "Unisex"} ) );
            }
        }
        WHEN( "Getting a family name" ) {
            std::string name = Name::get( nameFlags::IsFamilyName );
            CHECK( name == "Family" );
        }
        WHEN( "Getting a male backer name" ) {
            for( int i = 0; i < 8; ++i ) {
                std::string name = Name::get( nameFlags::IsMaleName | nameFlags::IsFullName );
                CHECK_THAT( name, IsOneOf( {"Male Backer", "Unisex Backer", "Male 'Nick' Backer", "Unisex 'Nick' Backer"} ) );
            }
        }
        WHEN( "Getting a female backer name" ) {
            for( int i = 0; i < 8; ++i ) {
                std::string name = Name::get( nameFlags::IsFemaleName | nameFlags::IsFullName );
                CHECK_THAT( name, IsOneOf( {"Female Backer", "Unisex Backer", "Female 'Nick' Backer", "Unisex 'Nick' Backer"} ) );
            }
        }
        WHEN( "Getting an invalid name" ) {
            std::string name = Name::get( nameFlags::IsUnisexName | nameFlags::IsTownName );
            CHECK( name == "Tom" );
        }
        WHEN( "Generating a male name" ) {
            for( int i = 0; i < 16; ++i ) {
                std::string name = Name::generate( true );
                CHECK_THAT( name, IsOneOf( {"Male Backer", "Unisex Backer", "Male Family", "Unisex Family", "Male 'Nick' Backer", "Unisex 'Nick' Backer", "Male 'Nick' Family", "Unisex 'Nick' Family"} ) );
            }
        }
        WHEN( "Generating a female name" ) {
            for( int i = 0; i < 16; ++i ) {
                std::string name = Name::generate( false );
                CHECK_THAT( name, IsOneOf( {"Female Backer", "Unisex Backer", "Female Family", "Unisex Family", "Female 'Nick' Backer", "Unisex 'Nick' Backer", "Female 'Nick' Family", "Unisex 'Nick' Family"} ) );
            }
        }
    }
}

