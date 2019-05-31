#include <iostream>  // cout, endl
#include <cassert>   // assert()
#include "list.h"

template < typename T = int >
sc::list<T> createVec( const sc::list<T> & _v )
{
    sc::list<T> temp( _v );
    return _v;
}

// The vector/iterator driver.
int main( void )
{
    auto n_unit{0};
    // Unit #1: default constructor
    {
        std::cout << ">>> Unit teste #" << ++n_unit << ": default constructor.\n";
        sc::list<int> seq;
        assert( seq.size() == 0 );
        assert( seq.empty() == true );
        std::cout << ">>> Passed!\n\n";
    }
        // Unit #2: constructor (size)
    {
        std::cout << ">>> Unit teste #" << ++n_unit << ": constructor(size).\n";
        sc::list<int> seq(10);
        assert( seq.size() == 10 );
        assert( seq.empty() == false );
        std::cout << ">>> Passed!\n\n";
    }

    // Unit #3: initializer list constructor
    {
        std::cout << ">>> Unit teste #" << ++n_unit << ": initializer list constructor.\n";
        sc::list<int> seq{ 1, 2, 3, 4, 5 };
        assert( seq.size() == 5 );
        assert( seq.empty() == false );

        // recover elements to test.
        auto i{0};
        for ( auto it = seq.begin() ; it != seq.end() ; ++it, ++i )
            assert( *it == i+1 );

        std::cout << ">>> Passed!\n\n";
    }

    // Unit: Assign operator.
    {
        std::cout << ">>> Unit teste #" << ++n_unit << ": assign operator.\n";
        sc::list<int> seq{ 1, 2, 3, 4, 5 };
        sc::list<int> seq2;

        seq2 = seq;
        assert( seq2.size() == 5 );
        assert( seq2.empty() == false );

        // recover elements to test.
        auto i{1};
        for( auto e : seq2 )
            assert ( e == i++ );

        std::cout << ">>> Passed!\n\n";
    }

    {
        std::cout << ">>> Unit teste #" << ++n_unit << ": initializer list assignment.\n";
        sc::list<int> seq = { 1, 2, 3, 4, 5 };

        assert( seq.size() == 5 );
        assert( seq.empty() == false );

        // recover elements to test.
        auto i{1};
        for( auto e : seq )
            assert ( e == i++ );

        std::cout << ">>> Passed!\n\n";
    }

    {
        std::cout << ">>> Unit teste #" << ++n_unit << ": clear().\n";
        sc::list<int> seq { 1, 2, 3, 4, 5 };

        assert( seq.size() == 5 );
        assert( seq.empty() == false );

        seq.clear();
        assert( seq.size() == 0 );
        assert( seq.empty() == true );

        std::cout << ">>> Passed!\n\n";
    }

    {
        std::cout << ">>> Unit teste #" << ++n_unit << ": push_front().\n";

        // #1 From an empty vector.
        sc::list<int> seq;

        assert( seq.empty() == true );
        for ( auto i{0u} ; i < 5 ; ++i )
        {
            seq.push_front( i+1 );
            assert( seq.size() == i+1 );
        }
        assert( seq.empty() == false );

        auto i{5};
        for ( const auto & e: seq )
            assert( e == i-- );

        seq.clear();
        assert( seq.empty() == true );
        for ( auto i{0u} ; i < 5 ; ++i )
        {
            seq.push_front( i+1 );
            assert( seq.size() == i+1 );
        }
        assert( seq.empty() == false );
        i = 5;
        for ( const auto & e: seq )
            assert( e == i-- );

        std::cout << ">>> Passed!\n\n";
    }

    {
        std::cout << ">>> Unit teste #" << ++n_unit << ": push_back().\n";

        // #1 From an empty vector.
        sc::list<int> seq;

        assert( seq.empty() == true );
        for ( auto i{0u} ; i < 5 ; ++i )
        {
            seq.push_back( i+1 );
            assert( seq.size() == i+1 );
        }
        assert( seq.empty() == false );

        auto i{0};
        for ( const auto & e: seq )
            assert( e == ++i );

        seq.clear();
        assert( seq.empty() == true );
        for ( auto i{0u} ; i < 5 ; ++i )
        {
            seq.push_back( i+1 );
            assert( seq.size() == i+1 );
        }
        assert( seq.empty() == false );
        i = 0;
        for ( const auto & e: seq )
            assert( e == ++i );

        std::cout << ">>> Passed!\n\n";
    }

    {
        std::cout << ">>> Unit teste #" << ++n_unit << ": pop_back().\n";

        // #1 From an empty vector.
        sc::list<int> seq { 1, 2, 3, 4, 5 };

        while( not seq.empty() )
        {
            seq.pop_back();
            // Checke whether we have the same list except for the last.
            auto i {0};
            for ( const auto & e: seq )
                assert( e == ++i );
        }

        std::cout << ">>> Passed!\n\n";
    }

    {
        std::cout << ">>> Unit teste #" << ++n_unit << ": pop_front().\n";

        // #1 From an empty vector.
        sc::list<int> seq { 1, 2, 3, 4, 5 };

        auto start{1};
        while( not seq.empty() )
        {
            seq.pop_front();
            // Check whether we have the same list except for the first.
            auto i {start};
            for ( const auto & e: seq )
                assert( e == ++i );

            start++;
        }

        std::cout << ">>> Passed!\n\n";
    }

    {
        std::cout << ">>> Unit teste #" << ++n_unit << ": front().\n";

        // #1 From an empty vector.
        sc::list<int> seq { 1, 2, 3, 4, 5 };

        auto i{0};
        while( not seq.empty() )
        {
            assert( seq.front() == ++i );
            seq.pop_front();
        }

        std::cout << ">>> Passed!\n\n";
    }

    {
        std::cout << ">>> Unit teste #" << ++n_unit << ": back().\n";

        // #1 From an empty vector.
        sc::list<int> seq { 1, 2, 3, 4, 5 };

        auto i{5};
        while( not seq.empty() )
        {
            assert( seq.back() == i-- );
            seq.pop_back();
        }

        std::cout << ">>> Passed!\n\n";
    }

    {
        std::cout << ">>> Unit teste #" << ++n_unit << ": operator==().\n";

        // #1 From an empty vector.
        sc::list<int> seq { 1, 2, 3, 4, 5 };
        sc::list<int> seq2 { 1, 2, 3, 4, 5 };
        sc::list<int> vec3 { 1, 2, 8, 4, 5 };
        sc::list<int> vec4 { 8, 4, 5 };

        assert( seq == seq2 );
        assert( not ( seq == vec3 ) );
        assert( not ( seq == vec4 ) );
        assert( seq == ( sc::list<int>{ 1, 2, 3, 4, 5 } ) );

        std::cout << ">>> Passed!\n\n";
    }

    {
        std::cout << ">>> Unit teste #" << ++n_unit << ": operator!=().\n";

        // #1 From an empty vector.
        sc::list<int> seq { 1, 2, 3, 4, 5 };
        sc::list<int> seq2 { 1, 2, 3, 4, 5 };
        sc::list<int> vec3 { 1, 2, 8, 4, 5 };
        sc::list<int> vec4 { 8, 4, 5 };

        assert( not( seq != seq2 ) );
        assert( seq != vec3 );
        assert( seq != vec4 );
        assert( seq != ( sc::list<int>{ 1, 2, 3 } ) );

        std::cout << ">>> Passed!\n\n";
    }

    {
        std::cout << ">>> Unit teste #" << ++n_unit << ": insert(pos, value).\n";

        // #1 From an empty vector.
        sc::list<int> seq { 1, 2, 3, 4, 5 };

        seq.insert( seq.begin(), 0 );
        assert( seq == ( sc::list<int>{ 0, 1, 2, 3, 4, 5 } ) );

        std::cout << ">>> Passed!\n\n";
    }



    return 0;
}
