// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2013 Elephancoin Developers
// Copyright (c) 2014 RecyclingCoin Developer
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

	// no checkpoint now, can be added in later releases
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
//(0, uint256("0x"))
(0,    uint256("0x1ff241bee7a75327e99bcb2ca04331dca250622d41696f13eaf79fad72271725"))
(1,    uint256("0xab40265fa46b7e55f048a9015c40efe6ac5fd589806e768bf17527c1669866fc"))
(10,   uint256("0xbef054bf0ed96c8eb9e81807dd5da5b6ac4a9009bba90b8bef3312c3b7957952"))
(20,   uint256("0x5211a1080da73aaef6a0995d196a946c112aa150b44c0a506eda5792879563b3"))
(30,   uint256("0x1c7b341dbea115215845327b3930c708ca51c44211ebe54a8ae12b7148150bdd"))
(34,   uint256("0x7957c3d7d9dbf96475fd5f4ad6a9580b3c5f0c45b66f1d50afefa7fb615079ed"))
;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;

//### Default Value
return hash == i->second;

//### Produce Value
//return true;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;

//### Default Value
return mapCheckpoints.rbegin()->first;

//### Produce Value
//return 0;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
//### Default Value
return t->second;

//### Produce Value
//return NULL;
        }
        return NULL;
    }
}
