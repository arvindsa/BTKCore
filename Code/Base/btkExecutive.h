/* 
 * The Biomechanical ToolKit
 * Copyright (c) 2009-2015, Arnaud Barré
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 *     * Redistributions of source code must retain the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials
 *       provided with the distribution.
 *     * Neither the name(s) of the copyright holders nor the names
 *       of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written
 *       permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __btkExecutive_h
#define __btkExecutive_h

#include "btkObject.h"
#include "btkInformation.h"
#include "btkMacros.h" // _BTK_NOEXCEPT

namespace btk
{
  class Algorithm;
  enum class Result : short;
  
  class ExecutivePrivate;
  
  class BTK_BASE_EXPORT Executive : public Object
  {
    BTK_DECLARE_PIMPL_ACCESSOR(Executive)
    
  public:
    Executive(Algorithm* algorithm);
    virtual ~Executive() _BTK_NOEXCEPT;
    
    Executive(const Executive& ) = delete;
    Executive(Executive&& ) _BTK_NOEXCEPT = delete;
    Executive& operator=(const Executive& ) = delete;
    Executive& operator=(Executive&& ) _BTK_NOEXCEPT = delete;
    
    virtual Result runAlgorithm();
    
  protected:
    Algorithm* algorithm() const _BTK_NOEXCEPT;
    bool isPipelineModified();
    void updatePipelineTimestamp();
    Result sendRequest(Information& info) const _BTK_NOEXCEPT;
  };
};

#endif // __btkExecutive_h