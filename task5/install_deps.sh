python_exe=$1

check_pip=$(${python_exe} -m pip)
error_code=$?

if [ $error_code -ne 0 ]
then
    echo "Installing pip"
    wget https://bootstrap.pypa.io/get-pip.py -O /tmp/get-pip.py
    sudo ${python_exe} /tmp/get-pip.py
fi
echo $error_code
${python_exe} -m pip install --user --upgrade pip
${python_exe} -m pip install --user virtualenv

${python_exe} -m virtualenv PythonEnvironment -p ${python_exe}
python_path=PythonEnvironment/bin/python

${python_path} -m pip install gcovr
