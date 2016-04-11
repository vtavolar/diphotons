#!/bin/bash

version=$1
if [[ -z $version ]]; then
   echo "usage: $0 <version>"
   exit -1
fi

set -x 

## fggRunJobs.py --load ../config/jobs_diphoton_76.json     ../config/high_mass_analysis.py applyDiphotonCorrections=1 maxEvents=-1  -d full_analysis_moriond16v1_sync_${version}_data -n 50 -H -q 1nh  &

## fggRunJobs.py --load ../config/jobs_diphoton_76.json     ../config/high_mass_analysis.py applyDiphotonCorrections=1 maxEvents=-1 useVtx0=1 -d full_analysis_moriond16v1_sync_${version}_data -n 100 -H -q 1nh  &

fggRunJobs.py --load ../config/jobs_diphoton_76.json     ../config/high_mass_analysis.py applyDiphotonCorrections=1 maxEvents=-1 useVtx0=1 -d full_analysis_moriond16v1_sync_${version}_data -n 50 -H -q 1nd --no-use-tarball  &

## fggRunJobs.py --load ../config/jobs_diphoton_76.json     ../config/high_mass_analysis.py applyDiphotonCorrections=1 maxEvents=10 useVtx0=1 -d full_analysis_moriond16v1_sync_${version}_data_test -n 1 -H  &

## fggRunJobs.py --load ../config/jobs_diphoton_qcd.json     ../config/high_mass_analysis.py maxEvents=-1  -d full_analysis_moriond16v1_sync_${version}_qcd -n 20 -q 1nd -H &

## fggRunJobs.py --load ../config/jobs_diphoton_runD.json     ../config/high_mass_analysis.py addRegressionInput=1 maxEvents=-1  -d full_analysis_moriond16v1_sync_${version}_data -n 30 -q 1nd -H &
## fggRunJobs.py --load ../config/jobs_diphoton.json     ../config/high_mass_analysis.py applyDiphotonCorrections=1  maxEvents=-1  -d full_analysis_moriond16v1_sync_${version} -n 30 -q 1nd -H &

# fggRunJobs.py --load ../config/jobs_photon_runD.json       ../config/high_mass_analysis.py maxEvents=-1  -d single_photon_moriond16v1_sync_${version}_data -n 20 -q 1nd -H &
## fggRunJobs.py --load ../config/jobs_photon.json       ../config/high_mass_analysis.py maxEvents=-1  -d single_photon_moriond16v1_sync_${version} -n 20 -q 1nd -H &

### fggRunJobs.py --load ../config/jobs_dielectron_runD.json      ../config/high_mass_analysis.py applyDiphotonCorrections=1 maxEvents=-1  -d double_ele_moriond16v1_sync_${version}_data -n 40 -q 1nd -H &
### fggRunJobs.py --load ../config/jobs_dielectron.json      ../config/high_mass_analysis.py  applyDiphotonCorrections=1 maxEvents=-1  -d double_ele_moriond16v1_sync_${version} -n 40 -q 1nd -H &

## fggRunJobs.py --load ../config/jobs_diphoton_rereco.json     ../config/high_mass_analysis.py addRegressionInput=1 maxEvents=-1  -d full_analysis_moriond16v1_sync_${version}_data -n 200 -q 1nd -H &

## fggRunJobs.py --load ../config/jobs_dielectron_rereco.json      ../config/high_mass_analysis.py applyDiphotonCorrections=1 maxEvents=-1  -d double_ele_moriond16v1_sync_${version}_data -n 200 -q 1nd -H &

## fggRunJobs.py --load ../config/jobs_dielectron_76.json      ../config/high_mass_analysis.py applyDiphotonCorrections=1 maxEvents=-1  -d double_ele_moriond16v1_sync_${version}_data -n 50 -q 1nd -H &

## fggRunJobs.py --load ../config/jobs_dielectron_76.json      ../config/high_mass_analysis.py applyDiphotonCorrections=1 maxEvents=10000  -d double_ele_moriond16v1_sync_${version}_data -n 1 --no-use-tarball &

## fggRunJobs.py --load ../config/jobs_gen_spin0.json     ../config/gen_only_analysis.py useAAA=1 maxEvents=-1  -d full_analysis_gen_only_spin0_v1 -n 2 -q 8nh --no-copy-proxy -H &

# 

wait
