/*
* Copyright 2010-2016 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#include <aws/ec2/model/CreateVpcEndpointResponse.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/AmazonWebServiceResult.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/logging/LogMacros.h>

#include <utility>

using namespace Aws::EC2::Model;
using namespace Aws::Utils::Xml;
using namespace Aws::Utils::Logging;
using namespace Aws::Utils;
using namespace Aws;

CreateVpcEndpointResponse::CreateVpcEndpointResponse()
{
}

CreateVpcEndpointResponse::CreateVpcEndpointResponse(const AmazonWebServiceResult<XmlDocument>& result)
{
  *this = result;
}

CreateVpcEndpointResponse& CreateVpcEndpointResponse::operator =(const AmazonWebServiceResult<XmlDocument>& result)
{
  const XmlDocument& xmlDocument = result.GetPayload();
  XmlNode rootNode = xmlDocument.GetRootElement();
  XmlNode resultNode = rootNode;
  if (rootNode.GetName() != "CreateVpcEndpointResponse")
  {
    resultNode = rootNode.FirstChild("CreateVpcEndpointResponse");
  }

  if(!resultNode.IsNull())
  {
    XmlNode vpcEndpointNode = resultNode.FirstChild("vpcEndpoint");
    if(!vpcEndpointNode.IsNull())
    {
      m_vpcEndpoint = vpcEndpointNode;
    }
    XmlNode clientTokenNode = resultNode.FirstChild("clientToken");
    if(!clientTokenNode.IsNull())
    {
      m_clientToken = StringUtils::Trim(clientTokenNode.GetText().c_str());
    }
  }

  XmlNode responseMetadataNode = rootNode.FirstChild("ResponseMetadata");
  m_responseMetadata = responseMetadataNode;
  AWS_LOGSTREAM_DEBUG("Aws::EC2::Model::CreateVpcEndpointResponse", "x-amzn-request-id: " << m_responseMetadata.GetRequestId() );

  return *this;
}