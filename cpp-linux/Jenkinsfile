pipeline {
    agent any

    environment {
        // Path where you want to store a copy locally on EC2
        STORAGE_PATH = "/var/lib/jenkins/artifacts/calculator"
    }

    stages {
        stage('Initialize') {
            steps {
                sh "mkdir -p build ${STORAGE_PATH}"
            }
        }

        stage('Run Tests') {
            steps {
                // Build and run tests using the native Linux compiler
                sh '''
                g++ tests/test_logic.cpp -o native_test
                ./native_test
                '''
            }
        }

        stage('Cross-Compile for Windows') {
            steps {
                // Using MinGW to create the .exe
                sh '''
                cd build
                x86_64-w64-mingw32-g++ ../src/main.cpp -o calculator.exe -static-libgcc -static-libstdc++ -static
                '''
            }
        }

        stage('Store & Archive') {
            steps {
                // 1. Store in a specific path on the EC2 server
                sh "cp build/calculator.exe ${STORAGE_PATH}/calculator_latest.exe"
                
                // 2. Archive in Jenkins so it's downloadable from the browser
                archiveArtifacts artifacts: 'build/*.exe', fingerprint: true
            }
        }
    }
}
