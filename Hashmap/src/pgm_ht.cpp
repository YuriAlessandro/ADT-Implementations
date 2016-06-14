#include <iostream>
#include <functional>
#include <tuple>
#include "hashtbl.h"

using namespace std;

struct Account
{
    std::string mClientName;// (key) Client's name.
    int mBankCode;          // (key) Bank code.
    int mBranchCode;        // (key) Branch code.
    int mNumber;            // (key) Account number.
    float mBalance;         // Account balance.


    #ifdef V1
    using AcctKey = int;
    #endif

    #ifdef V2
    using AcctKey = std::pair<std::string, int>;
    #endif
    
    #ifdef V3
    using AcctKey = std::tuple<std::string, int, int, int>;
    #endif


    Account( std::string _Name = "<empty>",
             int _BankCode = 1,  // Banco do Brasil.
             int _BranchCode = 1668, // Agencia UFRN.
             int _Number = 0,
             float _Balance = 0.f )
        :  mClientName( _Name ),
           mBankCode( _BankCode ),
           mBranchCode( _BranchCode ), 
           mNumber( _Number ), 
           mBalance( _Balance )
        { /* Empty */ }
    
    AcctKey getKey () const;
    
    const Account& operator= ( const Account& rhs )
    {
        // Avoid assigning to itself.
        if( this != &rhs )
        {
            // Copy new values.
            this->mClientName = rhs.mClientName;
            this->mBankCode   = rhs.mBankCode;
            this->mBranchCode = rhs.mBranchCode;
            this->mNumber     = rhs.mNumber;
            this->mBalance    = rhs.mBalance;
        }
        return *this;
    }

    inline friend std::ostream &operator<< ( std::ostream& _os, const Account& _acc )
    {
        _os << "[ Client: <"  << _acc.mClientName <<
               "> Bank: <"    << _acc.mBankCode <<
               "> Branch: <"  << _acc.mBranchCode <<
               "> Number: <"  << _acc.mNumber <<
               "> Balance: <" << _acc.mBalance << "> ]";
        return _os;
    }
};

#ifdef V1

/*!
 * \brief Gera a chave (versão 1) que eh igual a conta corrente.
 */

Account::AcctKey Account::getKey () const
{
    return mNumber;
}

    
    
struct KeyHash {
    std::size_t operator()(const Account::AcctKey& k) const
    {
        return std::hash<int>()( k );
    }
};

#endif

#ifdef V2
/*!
 * \brief Gera a chave (versão 2) que eh um par do nome do cliente com a conta corrente.
 */
    
Account::AcctKey Account::getKey () const
{
    return std::pair<std::string, int>(mClientName, mNumber);
}

struct KeyHash {
    std::size_t operator()(const Account::AcctKey& k) const
    {
        return std::hash<std::string>()( k.first ) ^ std::hash<int>()( k.second );
    
    }
};
#endif

#ifdef V3
/*!
 * \brief Gera a chave (versão 3) que eh igual a uma tupla do nome do cliente,
 * o código do banco, da agência, e da conta corrente.
 */

Account::AcctKey Account::getKey () const
{
    return std::tuple<std::string, int, int, int>(mClientName, mBankCode, mBranchCode, mNumber);
}

struct KeyHash {
    std::size_t operator()(const Account::AcctKey& k) const
    {
        return std::hash<std::string>()( std::get<0>(k) ) ^ std::hash<int>()( std::get<1>(k) )
        ^ std::hash<int>()( std::get<2>(k) ) ^ std::hash<int>()( std::get<3>(k) );
    }
};

#endif


// Como o operador = já está definido para os membros de std::tuple, não é
// necessária nenhuma modificação.
struct KeyEqual {
    bool operator()(const Account::AcctKey& lhs, const Account::AcctKey& rhs) const
    {
        return lhs == rhs;
    }
};


int main( void )
{
    MyHashTable::HashTbl< Account::AcctKey, Account, KeyHash, KeyEqual > accounts(3); // Hash table shall heve size 5.
    Account MyAccts[] =
    {
        { "Jose Silva",    1, 1668, 20123, 1500.f },
        { "Carlos Prado",  1, 1668, 35091, 1250.f },
        { "Aline Bastos", 13,   33, 55723,  500.f },
        { "Pedro Gomes",   1, 1801, 87661, 5800.f },
        { "Helen Sousa",   4, 2345, 12321, 3200.f },
    };

    Account::AcctKey searchKey; // An account key
    auto nAccts = sizeof( MyAccts ) / sizeof( Account );
    
    Account acct;

    for ( auto i(0u) ; i < nAccts ; ++i )
    {
        accounts.insert( MyAccts[i].getKey() , MyAccts[i] );
    }

    accounts.showStructure();

    std::cout << "Number of elements in the HashTable: " << accounts.count();

#ifdef V1
    // Checks for accounts and prints records if found
    cout << endl;
    cout << "Enter account number (CTRL+D to exit program): ";
    while ( cin >> searchKey )
    {
        if ( accounts.retrieve( searchKey, acct ) )
        {
            cout << acct.mNumber << " " << acct.mBalance << endl;
            cout << "Removing this account....\n";
            accounts.remove( acct.getKey() );
        }
        else
            cout << "Account " << searchKey << " not found." << endl;

        cout << "Enter account number (CTRL+D to exit program): ";
    }

    std::cout << "Number of elements in the HashTable: " << accounts.count();

#endif
    std::cout << "\n>>> Normal exiting...\n";

    return EXIT_SUCCESS;
}