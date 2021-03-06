/**
 * @file DimensionalityRedox.hpp
 * @brief This header file contains dimensionality reduction algoritm base classs.
 * @author Krzysztof Adamkiewicz
 * @date 16/1/2020
 */

// This file is a part of Cluster - Application for image clustering.
// Copyright (C) 2020 Krzysztof Adamkiewicz <kadamkiewicz835@gmail.com>
// 
// This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

#ifndef DIMENSIONALITY_REDOX_HPP_INCLUDED
#define DIMENSIONALITY_REDOX_HPP_INCLUDED

#include <vector>
#include <memory>
#include "../Types.hpp"

namespace magic
{
    /**
     * @brief Dimensionality reduction algorithm.
     */
    class DimReductionAlgorithm
    {
    public:
        /**
         * @brief Dimensionality algorithm reducition type.
         */
        enum Type
        {
            MDS_ALGORITHM,
            NONE
        };

        static std::shared_ptr<DimReductionAlgorithm> build(Type type);
        
        /**
         * @brief Reduce features vectors of the entire dataset.
         * @param dataset Image dataset.
         * @param outputDim Number of dimensions that the output is supposed to have.
         * @return Reduced feature dataset.
         */
        virtual FeatureDataset reduce(const FeatureDataset& dataset, unsigned short outputDim) = 0;
        
        virtual ~DimReductionAlgorithm();
    };
}

#endif
