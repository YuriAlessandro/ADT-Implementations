#include "hashtbl.h"

//! MyHashTable namespace encapsulates all class related to a simple hash function definition.
namespace MyHashTable {

    //----------------------------------------------------------------------------------------
    //! Default construtor.
    /*! Creates a hash table of the required capacity, which uses an external hash function
     *  that maps keys to unsigned long integers.
     *  If no external hash function is provided, an \r UndefinedHashFunctionException is generated.
     *  \param _initSize Required hash table capacity.
     *  \param _pfHF Pointer to an external hash function that does the first hashing and returns an unsigned long int.
     *  \throw UndefinedHashFunctionException if no external hash function is provided.
    */
    template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    HashTbl< KeyType, DataType, KeyHash, KeyEqual >::HashTbl ( int _initSize )
        : mSize( nextPrime( _initSize ) ), mCount( 0u )
    {
        mpDataTable = new std::list< Entry > [ mSize ];
    }                                                       

    //----------------------------------------------------------------------------------------
    //! Destrutor that just frees the table memory, clearing all collision lists.
    template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    HashTbl< KeyType, DataType, KeyHash, KeyEqual >::~HashTbl ()
    {
        for( auto i = 0; i < mSize; i++ )
            mpDataTable[i].clear();
            
        delete [] mpDataTable;
    }

    //----------------------------------------------------------------------------------------
    //! Inserts data into the hash table.
    /*! For an insertion to occur, the client code should provide a key and the data itself
     *  If the data is already stored in the table, the function updates the data with the
     *  new information provided.
     *  \param _newKey Key associated with the data, used to get to the stored information.
     *  \param _newDataItem Data to be stored or updated, in case the information is already stored in the hash table.
     *  \return true if the data is already stored in the table and it is updated; false, otherwise.
     *  \throw std::bad_alloc In case no memory is available for dynamic allocation required in the insertion procedure.
    */
    template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    bool HashTbl< KeyType, DataType, KeyHash, KeyEqual >::insert ( const KeyType & _newKey, const DataType & _newDataItem ) throw ( std::bad_alloc )
    {
        // Flag used to indicate whether the data has been found or not.
        bool bDataFound( false );
        
        size_t _pos = KeyHash()( _newKey ) % mSize;
        
        for ( auto it = mpDataTable[_pos].begin(); it != mpDataTable[_pos].end() and !bDataFound; it++ ){
            if ( KeyEqual()( _newKey, (*it).mKey ) ){
                bDataFound = true;
                (*it).mData = _newDataItem;
            }
        }
        
        if ( !bDataFound ){
            if ( mSize <= mCount ) this->rehash();
            
            mpDataTable[_pos].push_back( Entry( _newKey, _newDataItem ) );
            mCount++;
        }
    
        return bDataFound;
    }


    //----------------------------------------------------------------------------------------
    //! Removes data from the hash table.
    /*! Removes a data item from the table, based on the key associated with the data.
     *  If the data cannot be found, false is returned; otherwise, true is returned instead.
     *  \param _searchKey Data key to search for in the table.
     *  \return true if the data item is found; false, otherwise.
    */
    template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    bool HashTbl< KeyType, DataType, KeyHash, KeyEqual >::remove ( const KeyType & _searchKey )
    {
      
        auto bRemoved( false );
        
        size_t _pos = KeyHash()( _searchKey ) % mSize;
        
        for ( auto it = mpDataTable[_pos].begin(); it != mpDataTable[_pos].end() and !bRemoved; it++ ){
            if( KeyEqual()( (*it).mKey, _searchKey) ){
                mpDataTable[_pos].erase( it );
                bRemoved = true;
                mCount--;
            }
        }
        
        return bRemoved;
    }

    //----------------------------------------------------------------------------------------
    //! Retrieves data from the table.
    /*! Retrieves a data item from the table, based on the key associated with the data.
     *  If the data cannot be found, false is returned; otherwise, true is returned instead.
     *  \param _searchKey Data key to search for in the table.
     *  \param _dataItem Data record to be filled in when data item is found.
     *  \return true if the data item is found; false, otherwise.
    */
    template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    bool HashTbl< KeyType, DataType, KeyHash, KeyEqual >::retrieve ( const KeyType & _searchKey, DataType & _dataItem ) const
    {
        auto bFound( false );
        
        size_t _pos = KeyHash()( _searchKey ) % mSize;
        
        for ( auto it = mpDataTable[_pos].begin(); it != mpDataTable[_pos].end(); it++ ){
            if( KeyEqual()( (*it).mKey, _searchKey) ){
                _dataItem = (*it).mData;
                bFound = true;
            }
        }
        
        return bFound;
    }

    //! Clears the data table.
    template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    void HashTbl< KeyType, DataType, KeyHash, KeyEqual >::clear ()
    {
        for( auto i = 0; i < mSize; i++ )
            mpDataTable[i].clear();
    }

    //! Tests whether the table is empty.
    /*!
     * \return true is table is empty, false otherwise.
     */
    template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    bool HashTbl< KeyType, DataType, KeyHash, KeyEqual >::isEmpty () const
    {
        return ( mCount == 0 );
    }

    //! Counts the number of elements currently stored in the table.
    /*!
     * \return The current number of elements in the table.
     */
    template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    unsigned long int HashTbl< KeyType, DataType, KeyHash, KeyEqual >::count () const
    {
        return mCount;
    }

    //! Prints out the hash table content.
    template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    void HashTbl< KeyType, DataType, KeyHash, KeyEqual >::showStructure () const
    {
        KeyHash hashFn;

        // Traverse the list associated with the based address (idx), calculated before.
        for( auto i(0) ; i < mSize; ++i )
        {
            std::cout << i << " :{ key=";
            for( auto & e : mpDataTable[ i ] )
            {
                std::cout << hashFn( e.mKey ) << " ; " << e.mData << " " ;
            }
            std::cout << "}\n";
        }
    }
    
    template < typename KeyType, typename DataType, typename KeyHash, typename KeyEqual >
    void HashTbl< KeyType, DataType, KeyHash, KeyEqual >::rehash( void ){

        unsigned int _newSize = nextPrime( mSize*2 );
        std::list< Entry > *temp = new std::list< Entry > [ _newSize ];
        size_t _pos;

        for(auto i = 0u; i < mSize; i++ ){
            for( auto it = mpDataTable[i].begin(); it != mpDataTable[i].end(); it++){ 
                _pos = KeyHash()( (*it).mKey ) % _newSize; 
                temp[_pos].push_back( Entry( (*it).mKey, (*it).mData ) );
            }
        }
        
        clear();
        delete [] mpDataTable;
        
        mSize = _newSize;
        mpDataTable = temp;

    }
} // namespace MyHashTable

////////////////////////////////////////////////////////////////////////////////
// Coisas extras                                                              //
////////////////////////////////////////////////////////////////////////////////


unsigned int nextPrime( unsigned int _a ){
    while ( true ){
        if ( isPrime( _a ) ) return _a;
        _a++;
    }
}

bool isPrime( unsigned int _a ){
    for ( unsigned int i = 2; i <= sqrt( _a ); i++ )
        if ( _a % i == 0 )
            return false;

    return true;
}

