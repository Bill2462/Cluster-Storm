/**
 * @file ClusteringAlgorithm.cpp
 * @brief This source file contains source code for Clustering algorithm.
 * @author Krzysztof Adamkiewicz
 * @date 23/1/2020
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

#include "Clustering/DBSCAN.hpp"
#include "Clustering/K-Means.hpp"
#include "Clustering/K-Medians.hpp"
#include "Clustering/ROCK.hpp"

using namespace magic;

/**
 * @brief Build clustering algorithm.
 * @param type Clustering algorithm type.
 * @return Shared pointer to the clustering algorithm object. If type is invalid, returns nullptr.
 */
std::shared_ptr<ClusteringAlgorithm> ClusteringAlgorithm::build(ClusteringAlgorithm::Type type)
{
    switch(type)
    {
        case DBSCAN_ALGORITHM:
            return std::shared_ptr<ClusteringAlgorithm>(new DBSCAN);

        case K_MEANS_ALGORITHM:
            return std::shared_ptr<ClusteringAlgorithm>(new K_Means);

        case K_MEDIANS_ALGORITHM:
            return std::shared_ptr<ClusteringAlgorithm>(new K_Medians);

        case ROCK_ALGORITHM:
            return std::shared_ptr<ClusteringAlgorithm>(new ROCK);
    }

    return std::shared_ptr<ClusteringAlgorithm>(nullptr);
}

/**
 * @brief Copy features from the images dataset to separate vector.
 * @param dataset Images dataset.
 * @return Vector of feature vectors.
 */
std::vector<FeatureVector> ClusteringAlgorithm::copyFeatures(const ImageDataset& dataset) const
{
    std::vector<FeatureVector> features;
    features.resize(dataset.size());
    
    for(auto it=dataset.begin(); it<dataset.end(); it++)
        features.push_back((*it)->featureVector);

    return features;
}

/**
 * @brief Export clusters created by clustering library to the cluster format used by the rest
 * of the project.
 * @param clusters Clusters created by the cluster libary.
 * @return Vector of clusters.
 */
std::vector<Cluster> ClusteringAlgorithm::exportClusters(const pyclustering::clst::cluster_data& clusters, const ImageDataset& dataset) const
{
    //clusters data is a vector of vectors of size_t, each size_t is an index in the original image dataset
    std::vector<Cluster> output;
    for(auto it=clusters.clusters().begin(); it<clusters.clusters().end(); it++)
    {
        Cluster cluster;
        for(auto it2=(*it).begin(); it2<(*it).end(); it2++)
            cluster.push_back(dataset[*it2]);
    }

    return output;
}
