#include <iostream>  // cout, endl
#include <cassert>   // assert()
#include "../include/list.h"

template < typename T = int >
sc::list<T> createVec( const sc::list<T> & _v ) {
    sc::list<T> temp( _v );
    return _v;
}

// The vector/iterator driver.
int main( void ) {
    auto n_unit{0};
    // Unit #1: default constructor
    {
        std::cout << ">>> Unit teste #" << ++n_unit << ": default constructor.\n";
        sc::list<int> seq;
        assert( seq.size() == 0 );
        assert( seq.empty() == true );
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



    return 0;
}
