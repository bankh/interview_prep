# Interview Preparation
## Coding Preparation
{ CtCi: [Laakman] Cracking the coding interview from hackerrank challenge}
{ cppDSAL: [Anggoro] Cpp_data_structures_and_algorithms}

## Machine Learning and Deep Learning Parts:
## Build Instructions for DL Environment:
- Install Anaconda
  $> chmod +x {Anaconda_name}
  $> ./{Anaconda_name}

- export PATH=/home/{user_name}/anaconda3/bin

- Check the version of Conda
	- $> conda -V

- Update the conda
	- $> conda update conda

- Create a virtual environment for the project
	- $> conda create -n {your_env_name} python={python_ver} anaconda

- Activate your virtual environment
	- $> source activate keras

- Install Tensorflow to the keras environment	
	- Install tensorflow with GPU support
	```
	$pip install --ignore-installed --upgrade {Check the compatible version based on the ubuntu and other library versions}
	```
	
	* GPU support requires the following libraries for Anaconda (https://www.tensorflow.org/install/install_linux#InstallingAnaconda):
	
	** CUDA Toolkit https://developer.nvidia.com/cuda-80-ga2-download-archive
	Ubuntu 14.04 works with CUDA 8.0 only. The following is the debian local install commands:
```
$> sudo dpkg -i cuda-repo-ubuntu1404-8-0-local-ga2_8.0.61-1_amd64.deb
$> sudo apt-get update
$> sudo apt-get install cuda
```

	** cuDNN SDK v6. (Compatible with CUDA Toolkit)
	Use username and password to login and install runtime library, Developer Library for 6 Ubuntu 14.04. Also Code samples and UserGuide for Ubuntu 14.04. The current setup is compatible with tensorflow 1.6 and tensorboard 1.0.06a.
	1- Verify the installation:
		- Copy the cuDNN sample to a writable path:
```
		$cp -r /usr/src/cudnn samples v6 $HOME
		$cd $HOME/cudnn samples v6/mnistCUDNN
		$make clean && make
		$./mnistCUDNN
		>> Test Passed!
```
	ToDo: Check the following steps:
	2- GPU card with CUDA Compute Capability

	3- GPU Drivers supporting version of CUDA Toolkit
	libcupti-dev library, which is the NVidia Cuda Profile Tools Interface.

* Reminders:
To check the active environments in Conda:
$> conda-env list
Change the environment
$> source activate {environment_name}
