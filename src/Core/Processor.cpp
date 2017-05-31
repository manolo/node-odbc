// File: Processor.cpp
// 
// node-odbc (odbc interface for NodeJS)
// 
// Copyright 2017 Clemens Susenbeth
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
// http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "stdafx.h"
#include "Processor.h"

using namespace std::chrono;


CProcessor::CProcessor( )
{
	m_bStopProcessor = false;
}

CProcessor::~CProcessor( )
{
}

void CProcessor::StartProcessor( )
{
	assert( !m_thread.joinable( ) );

	m_thread = std::thread( [ & ] 
	{ 
		for( ;; )
		{
			const auto tmStart = steady_clock::now( );
			


			const auto tmWork = ( steady_clock::now( ) - tmStart );

			if( tmWork < 1s )
			{
				std::this_thread::sleep_for( 1s - tmWork );
			}
		}
	} );
}
