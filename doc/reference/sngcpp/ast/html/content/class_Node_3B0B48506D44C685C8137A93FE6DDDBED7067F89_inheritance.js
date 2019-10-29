// JavaScript source code for drawing class inheritance diagrams

function pick(level, classes) {
    var levelClasses = [];
    var n = classes.length;
    for (var i = 0; i < n; ++i) {
        var c = classes[i];
        if (c.level == level) {
            levelClasses.push(c);
        }
    }
    return levelClasses;
}

function createClassElements(levelClasses, maxTextWidth, maxTextHeight) {
    var textDimensions = { width: maxTextWidth, height: maxTextHeight };
    var n = levelClasses.length;
    for (var i = 0; i < n; ++i) {
        var levelClass = levelClasses[i];
        var svg = document.getElementById("classInheritanceDiagram");
        var rectElement = document.createElementNS('http://www.w3.org/2000/svg', 'rect');
        rectElement.setAttribute("id", levelClass.id + "_rect");
        var linkElement = document.createElementNS('http://www.w3.org/2000/svg', 'a');
        linkElement.setAttribute("href", levelClass.link);
        var textElement = document.createElementNS('http://www.w3.org/2000/svg', 'text');
        linkElement.appendChild(textElement);
        textElement.setAttribute("id", levelClass.id + "_text");
        textElement.innerHTML = levelClass.name;
        svg.appendChild(rectElement);
        svg.appendChild(linkElement);
        var bb = textElement.getBBox();
        var textWidth = bb.width;
        var textHeight = bb.height;
        levelClass.textWidth = textWidth;
        levelClass.textHeight = textHeight;
        if (textWidth > textDimensions.width) {
            textDimensions.width = textWidth;
        }
        if (textHeight > textDimensions.height) {
            textDimensions.height = textHeight;
        }
    }
    return textDimensions;
}

function drawDiagram(classes) {
    var cont = true;
    var level = 0;
    var yspace = 8;
    var xspace = 8;
    var minRectWidth = 100;
    var minRectHeight = 40;
    var maxTextWidth = 0;
    var maxTextHeight = 0;
    var triangleHeight = 20;
    var triangleWidth = 20;
    var targetHandleHeight = 20;
    var sourceHandleHeight = 40;
    var rectXSpace = 20;
    var horizontalRectYSpace = triangleHeight + targetHandleHeight + sourceHandleHeight;
    var verticalRectYSpace = 20;
    var derivedTriangleHeight = 8;
    var derivedTriangleWidth = 8;
    var widthThreshold = 1800;
    var allLevelClasses = [];
    while (cont) {
        var levelClasses = pick(level, classes);
        var n = levelClasses.length;
        cont = n > 0;
        if (cont) {
            var textDimensions = createClassElements(levelClasses, maxTextWidth, maxTextHeight);
            if (textDimensions.width > maxTextWidth) {
                maxTextWidth = textDimensions.width;
            }
            if (textDimensions.height > maxTextHeight) {
                maxTextHeight = textDimensions.height;
            }
            allLevelClasses.push(levelClasses);
            ++level;
        }
    }
    var maxLevel = level;
    var rectWidth = Math.max(minRectWidth, maxTextWidth + 2 * xspace);
    var rectHeight = Math.max(minRectHeight, maxTextHeight + 2 * yspace);
    var totalWidth = 0;
    var totalHeight = 0;
    var horizontalDirection = 0;
    var verticalDirection = 1;
    var levelDirection = [];
    var levelHeight = [];
    var prevW = 0;
    for (level = 0; level < maxLevel; ++level) {
        var levelClasses = allLevelClasses[level];
        var n = levelClasses.length;
        var w = n * (rectWidth + rectXSpace);
        var h = rectHeight + horizontalRectYSpace;
        if (w < widthThreshold) {
            levelDirection.push(horizontalDirection);
            if (w > totalWidth) {
                totalWidth = w;
            }
        }
        else {
            w = prevW + rectWidth + rectXSpace;
            h = n * (rectHeight + verticalRectYSpace);
            levelDirection.push(verticalDirection);
            totalWidth += w;
        }
        totalHeight += h;
        levelHeight.push(h);
        prevW = w;
    }
    var svg = document.getElementById("classInheritanceDiagram");
    svg.setAttribute("width", totalWidth.toString());
    svg.setAttribute("height", totalHeight.toString());
    var prevRectY = 0;
    var prevRectX = 0;
    var prevHandleX2 = -1;
    var prevHandleY2 = -1;
    var prevY = 0;
    for (level = 0; level < maxLevel; ++level) {
        var direction = levelDirection[level];
        var levelClasses = allLevelClasses[level];
        var n = levelClasses.length;
        var rectY = prevY;
        prevY += levelHeight[level];
        var rectX = (totalWidth / n - rectWidth) / 2;
        var minHandleX = Number.MAX_SAFE_INTEGER;
        var maxHandleX = 0;
        var handleY = 0;
        for (var i = 0; i < n; ++i) {
            var levelClass = levelClasses[i];
            var textWidth = levelClass.textWidth;
            var textHeight = levelClass.textHeight;
            if (direction == horizontalDirection) {
                rectX = (totalWidth / n - rectWidth) / 2 + i * (rectWidth + rectXSpace);
            }
            else if (direction == verticalDirection) {
                rectX = prevRectX + (rectWidth + rectXSpace);
                rectY = prevRectY + horizontalRectYSpace + i * (rectHeight + verticalRectYSpace);
            }
            var textX = rectX + (rectWidth - textWidth) / 2;
            var textY = (rectY + rectHeight - yspace / 2) - (rectHeight - textHeight) / 2;
            var rectElement = document.getElementById(levelClass.id + "_rect");
            rectElement.setAttribute("x", rectX.toString());
            rectElement.setAttribute("y", rectY.toString());
            rectElement.setAttribute("width", rectWidth.toString());
            rectElement.setAttribute("height", rectHeight.toString());
            var fillColor = "white";
            if (levelClass.subject) {
                fillColor = "floralWhite";
            }
            rectElement.setAttribute("fill", fillColor);
            rectElement.setAttribute("stroke", "black");
            var textElement = document.getElementById(levelClass.id + "_text");
            textElement.setAttribute("x", textX.toString());
            textElement.setAttribute("y", textY.toString());
            if (level < maxLevel - 1) {
                var triangleElement = document.createElementNS('http://www.w3.org/2000/svg', 'polygon');
                var tipX = rectX + rectWidth / 2;
                var tipY = rectY + rectHeight;
                var leftX = tipX - triangleWidth / 2;
                var leftY = rectY + rectHeight + triangleHeight;
                var rightX = tipX + triangleWidth / 2;
                var rightY = rectY + rectHeight + triangleHeight;
                triangleElement.setAttribute("points",
                    tipX.toString() + "," + tipY.toString() + " " +
                    leftX.toString() + "," + leftY.toString() + " " +
                    rightX.toString() + "," + rightY.toString());
                triangleElement.setAttribute("fill", "white");
                triangleElement.setAttribute("stroke", "black");
                svg.appendChild(triangleElement);
                var targetHandleElement = document.createElementNS('http://www.w3.org/2000/svg', 'line');
                var handleX1 = tipX;
                var handleY1 = tipY + triangleHeight;
                var handleX2 = tipX;
                var handleY2 = tipY + triangleHeight + targetHandleHeight;
                targetHandleElement.setAttribute("x1", handleX1.toString());
                targetHandleElement.setAttribute("y1", handleY1.toString());
                targetHandleElement.setAttribute("x2", handleX2.toString());
                targetHandleElement.setAttribute("y2", handleY2.toString());
                targetHandleElement.setAttribute("stroke", "black");
                svg.appendChild(targetHandleElement);
                prevHandleX2 = handleX1;
                prevHandleY2 = handleY1;
                if (handleX1 < minHandleX) {
                    minHandleX = handleX1;
                    handleY = handleY2;
                }
                if (handleX1 > maxHandleX) {
                    maxHandleX = handleX1;
                    handleY = handleY2;
                }
            } else if (level == maxLevel - 1 && levelClass.hasDerivedClasses) {
                var derivedTriangleElement = document.createElementNS('http://www.w3.org/2000/svg', 'polygon');
                var cornerX = rectX + rectWidth;
                var cornerY = rectY + rectHeight;
                var verticalX = rectX + rectWidth;
                var verticalY = rectY + rectHeight - derivedTriangleHeight;
                var horizontalX = rectX + rectWidth - derivedTriangleWidth;
                var horizontalY = rectY + rectHeight;
                derivedTriangleElement.setAttribute("points",
                    cornerX.toString() + "," + cornerY.toString() + " " +
                    verticalX.toString() + "," + verticalY.toString() + " " +
                    horizontalX.toString() + "," + horizontalY.toString());
                derivedTriangleElement.setAttribute("fill", "black");
                svg.appendChild(derivedTriangleElement);
            }
            if (level > 0 && direction == horizontalDirection) {
                var sourceHandleElement = document.createElementNS('http://www.w3.org/2000/svg', 'line');
                var handleX1 = rectX + rectWidth / 2;
                var handleY1 = rectY;
                var handleX2 = rectX + rectWidth / 2;
                var handleY2 = rectY - sourceHandleHeight;
                sourceHandleElement.setAttribute("x1", handleX1.toString());
                sourceHandleElement.setAttribute("y1", handleY1.toString());
                sourceHandleElement.setAttribute("x2", handleX2.toString());
                sourceHandleElement.setAttribute("y2", handleY2.toString());
                sourceHandleElement.setAttribute("stroke", "black");
                svg.appendChild(sourceHandleElement);
                if (handleX1 < minHandleX) {
                    minHandleX = handleX1;
                    handleY = handleY2;
                }
                if (handleX1 > maxHandleX) {
                    maxHandleX = handleX1;
                    handleY = handleY2;
                }
            }
            else if (level > 0 && direction == verticalDirection) {
                var sourceHandleElement = document.createElementNS('http://www.w3.org/2000/svg', 'line');
                var handleX1 = rectX;
                var handleY1 = rectY + rectHeight / 2;
                var handleX2 = rectX - rectWidth / 2 - rectXSpace;
                var handleY2 = rectY + rectHeight / 2;
                sourceHandleElement.setAttribute("x1", handleX1.toString());
                sourceHandleElement.setAttribute("y1", handleY1.toString());
                sourceHandleElement.setAttribute("x2", handleX2.toString());
                sourceHandleElement.setAttribute("y2", handleY2.toString());
                sourceHandleElement.setAttribute("stroke", "black");
                svg.appendChild(sourceHandleElement);
                if (prevHandleX2 != -1 && prevHandleY2 != -1) {
                    var connectorHandleElement = document.createElementNS('http://www.w3.org/2000/svg', 'line');
                    connectorHandleElement.setAttribute("x1", handleX2.toString());
                    connectorHandleElement.setAttribute("y1", handleY2.toString());
                    connectorHandleElement.setAttribute("x2", prevHandleX2.toString());
                    connectorHandleElement.setAttribute("y2", prevHandleY2.toString());
                    connectorHandleElement.setAttribute("stroke", "black");
                    svg.appendChild(connectorHandleElement);
                }
                prevHandleX2 = handleX2
                prevHandleY2 = handleY2;
            }
        }
        if (minHandleX < maxHandleX && direction == horizontalDirection) {
            var hlineElement = document.createElementNS('http://www.w3.org/2000/svg', 'line');
            hlineElement.setAttribute("x1", minHandleX.toString());
            hlineElement.setAttribute("y1", handleY.toString());
            hlineElement.setAttribute("x2", maxHandleX.toString());
            hlineElement.setAttribute("y2", handleY.toString());
            hlineElement.setAttribute("stroke", "black");
            svg.appendChild(hlineElement);
        }
        prevRectY = rectY;
        prevRectX = rectX;
    }
}

function drawClassInheritanceDiagram() {
    var classes = [
        { name: "sngcpp::ast::Node", id: "class_0", level: 0, subject: true, hasDerivedClasses: true, link: "./class_Node_3B0B48506D44C685C8137A93FE6DDDBED7067F89.html" },
        { name: "sngcpp::ast::AliasDeclarationNode", id: "class_1", level: 1, subject: false, hasDerivedClasses: false, link: "./class_AliasDeclarationNode_10402FF684BE7A307DBD58D52E2B317B134BE264.html" },
        { name: "sngcpp::ast::ArrayDeclaratorNode", id: "class_2", level: 1, subject: false, hasDerivedClasses: false, link: "./class_ArrayDeclaratorNode_DBA59B2348AE56712241812A53EE20C05AA81567.html" },
        { name: "sngcpp::ast::AssignCaptureNode", id: "class_3", level: 1, subject: false, hasDerivedClasses: false, link: "./class_AssignCaptureNode_27D6F75B329009DA733BBD3700723814B26287A8.html" },
        { name: "sngcpp::ast::BaseClassSpecifierNode", id: "class_4", level: 1, subject: false, hasDerivedClasses: false, link: "./class_BaseClassSpecifierNode_C9010E4DD83735E86655A086A18BB188BC94E4AA.html" },
        { name: "sngcpp::ast::BinaryNode", id: "class_5", level: 1, subject: false, hasDerivedClasses: true, link: "./class_BinaryNode_26C91921CA6DD0BE63655ECBBFF8C167D358B1DE.html" },
        { name: "sngcpp::ast::BreakStatementNode", id: "class_6", level: 1, subject: false, hasDerivedClasses: false, link: "./class_BreakStatementNode_D907D6C137DC609E987B2A9EC4418DE2E42DE210.html" },
        { name: "sngcpp::ast::CastExpressionNode", id: "class_7", level: 1, subject: false, hasDerivedClasses: false, link: "./class_CastExpressionNode_ED673063A7C81F228164D0772E91919A1A368CD2.html" },
        { name: "sngcpp::ast::CatchAllNode", id: "class_8", level: 1, subject: false, hasDerivedClasses: false, link: "./class_CatchAllNode_27C5F4729CA728E93710864DB9211410B65AEC54.html" },
        { name: "sngcpp::ast::ClassNode", id: "class_9", level: 1, subject: false, hasDerivedClasses: false, link: "./class_ClassNode_B06F46A751488B686D875BF28765AF2A104EE5EF.html" },
        { name: "sngcpp::ast::ConditionalExpressionNode", id: "class_10", level: 1, subject: false, hasDerivedClasses: false, link: "./class_ConditionalExpressionNode_1F8B641EFBDFC3607B4D79D9DD0761E37AD60427.html" },
        { name: "sngcpp::ast::ContinueStatementNode", id: "class_11", level: 1, subject: false, hasDerivedClasses: false, link: "./class_ContinueStatementNode_CF7A182D0616CF9AB87E5358217C29E485C58A96.html" },
        { name: "sngcpp::ast::CppCastExpressionNode", id: "class_12", level: 1, subject: false, hasDerivedClasses: false, link: "./class_CppCastExpressionNode_184B9A0ABA8D688BBC71A32F1AA792C86622D1AF.html" },
        { name: "sngcpp::ast::DoStatementNode", id: "class_13", level: 1, subject: false, hasDerivedClasses: false, link: "./class_DoStatementNode_603ADC1AA05B49545D9AE828E2708B0B65BE9B93.html" },
        { name: "sngcpp::ast::ElaborateClassNameNode", id: "class_14", level: 1, subject: false, hasDerivedClasses: false, link: "./class_ElaborateClassNameNode_F210D8E4ED4CC6B925B3259D6669155B89B07E80.html" },
        { name: "sngcpp::ast::EnumTypeNode", id: "class_15", level: 1, subject: false, hasDerivedClasses: false, link: "./class_EnumTypeNode_742B6AEC3845ABAF76692A4CA17EB41A26B488F5.html" },
        { name: "sngcpp::ast::EnumeratorNode", id: "class_16", level: 1, subject: false, hasDerivedClasses: false, link: "./class_EnumeratorNode_E1B360D299ABD7FC74863AB2CA7C5C6429832F6D.html" },
        { name: "sngcpp::ast::ForStatementNode", id: "class_17", level: 1, subject: false, hasDerivedClasses: false, link: "./class_ForStatementNode_E9C60AE4EA25A10C9746D6E6B2184D6B49D306D6.html" },
        { name: "sngcpp::ast::ForwardClassDeclarationNode", id: "class_18", level: 1, subject: false, hasDerivedClasses: false, link: "./class_ForwardClassDeclarationNode_A32432C5F18582F38A1566FE283383F06373D527.html" },
        { name: "sngcpp::ast::FunctionDeclaratorNode", id: "class_19", level: 1, subject: false, hasDerivedClasses: false, link: "./class_FunctionDeclaratorNode_4EBA1ECC56E8C1F0BB45D24FF59BD26AADC1C969.html" },
        { name: "sngcpp::ast::FunctionNode", id: "class_20", level: 1, subject: false, hasDerivedClasses: false, link: "./class_FunctionNode_FF33E683A8B619C8B0C68E2611A5570F3A4BADD6.html" },
        { name: "sngcpp::ast::FunctionPtrIdNode", id: "class_21", level: 1, subject: false, hasDerivedClasses: false, link: "./class_FunctionPtrIdNode_DFD2EC8BA4FA02EE5D6D9F13B0109A5ECCE6F8FA.html" },
        { name: "sngcpp::ast::GotoStatementNode", id: "class_22", level: 1, subject: false, hasDerivedClasses: false, link: "./class_GotoStatementNode_EAE07B7FF6164B75BAD09B2E9949D33FEED91652.html" },
        { name: "sngcpp::ast::HandlerNode", id: "class_23", level: 1, subject: false, hasDerivedClasses: false, link: "./class_HandlerNode_A7E54921D954123477FCE948F213B34EE4AF1E65.html" },
        { name: "sngcpp::ast::IdDeclaratorNode", id: "class_24", level: 1, subject: false, hasDerivedClasses: false, link: "./class_IdDeclaratorNode_8D2A8F5FFBDE065A43A1519036D9DF476AE19B2D.html" },
        { name: "sngcpp::ast::IdentifierNode", id: "class_25", level: 1, subject: false, hasDerivedClasses: true, link: "./class_IdentifierNode_D35F937A599960879450AE3A78F15A75B8B38405.html" },
        { name: "sngcpp::ast::IfStatementNode", id: "class_26", level: 1, subject: false, hasDerivedClasses: false, link: "./class_IfStatementNode_690F01C4A6AF4447794F72C75179CF3D3449FDBD.html" },
        { name: "sngcpp::ast::InitDeclaratorNode", id: "class_27", level: 1, subject: false, hasDerivedClasses: false, link: "./class_InitDeclaratorNode_0B94468547B968BA2C0286E75A8DC28EECA494C8.html" },
        { name: "sngcpp::ast::LambdaExpressionNode", id: "class_28", level: 1, subject: false, hasDerivedClasses: false, link: "./class_LambdaExpressionNode_8EAB242A1154BEB49E6CDEB72EEFA86405D54C07.html" },
        { name: "sngcpp::ast::LinkageSpecificationNode", id: "class_29", level: 1, subject: false, hasDerivedClasses: false, link: "./class_LinkageSpecificationNode_D8A925830B1217F15E8926C048493F535A59AAA5.html" },
        { name: "sngcpp::ast::LiteralNode", id: "class_30", level: 1, subject: false, hasDerivedClasses: true, link: "./class_LiteralNode_CD2EE481C2453E055EA0A1A47D845A6A5E5F0EFA.html" },
        { name: "sngcpp::ast::MemberAccessDeclarationNode", id: "class_31", level: 1, subject: false, hasDerivedClasses: false, link: "./class_MemberAccessDeclarationNode_E0F904CBD0B6CCEF311E44CDF4402D0CCA6AAE61.html" },
        { name: "sngcpp::ast::MemberDeclarationNode", id: "class_32", level: 1, subject: false, hasDerivedClasses: false, link: "./class_MemberDeclarationNode_44B15F34178D45004B25CEBCFF8ABF790AC48516.html" },
        { name: "sngcpp::ast::MemberFunctionPtrIdNode", id: "class_33", level: 1, subject: false, hasDerivedClasses: false, link: "./class_MemberFunctionPtrIdNode_1B89DAF5BF8E58F8381FD79C01270D5310F53D69.html" },
        { name: "sngcpp::ast::MemberInitializerNode", id: "class_34", level: 1, subject: false, hasDerivedClasses: false, link: "./class_MemberInitializerNode_36375DAC454AA7FDEAA5CEDD10015FE9759D6D3D.html" },
        { name: "sngcpp::ast::NewExpressionNode", id: "class_35", level: 1, subject: false, hasDerivedClasses: false, link: "./class_NewExpressionNode_6CE8CBB219536BBB5618356B7338DFFD655FC9A1.html" },
        { name: "sngcpp::ast::ParameterNode", id: "class_36", level: 1, subject: false, hasDerivedClasses: false, link: "./class_ParameterNode_C04B10A2ED38A6C5383CA46B1C6AC713CCFE0B57.html" },
        { name: "sngcpp::ast::RangeForStatementNode", id: "class_37", level: 1, subject: false, hasDerivedClasses: false, link: "./class_RangeForStatementNode_40456C6F00B7B00EFC6C6F8DF1F8D798AA15820C.html" },
        { name: "sngcpp::ast::RefCaptureNode", id: "class_38", level: 1, subject: false, hasDerivedClasses: false, link: "./class_RefCaptureNode_6A83281EA99E3F76D072BFBB9BCD8196A8E6093A.html" },
        { name: "sngcpp::ast::ReturnStatementNode", id: "class_39", level: 1, subject: false, hasDerivedClasses: false, link: "./class_ReturnStatementNode_3F2877807D2E2F2DD8FA2A9493B6C0F6DF9B609B.html" },
        { name: "sngcpp::ast::SimpleDeclarationNode", id: "class_40", level: 1, subject: false, hasDerivedClasses: false, link: "./class_SimpleDeclarationNode_62E86E1DA1C4D0792046C5FF5A06FAD1A51675E1.html" },
        { name: "sngcpp::ast::SimpleTypeNode", id: "class_41", level: 1, subject: false, hasDerivedClasses: false, link: "./class_SimpleTypeNode_C1B8B4343B9E5F70772809DEB68F19BD9BF25116.html" },
        { name: "sngcpp::ast::SourceFileNode", id: "class_42", level: 1, subject: false, hasDerivedClasses: false, link: "./class_SourceFileNode_84126815F2A18EDCEECEA25D712448FECD2DC365.html" },
        { name: "sngcpp::ast::SpecialMemberFunctionNode", id: "class_43", level: 1, subject: false, hasDerivedClasses: false, link: "./class_SpecialMemberFunctionNode_1D50B1136366D0CDE9B8D4AA3E814A81BBF0C2FD.html" },
        { name: "sngcpp::ast::SwitchStatementNode", id: "class_44", level: 1, subject: false, hasDerivedClasses: false, link: "./class_SwitchStatementNode_8CAA57C7B9EBE35296DBBBD59DE2FCAA5BBF8BE4.html" },
        { name: "sngcpp::ast::TemplateArgumentNode", id: "class_45", level: 1, subject: false, hasDerivedClasses: false, link: "./class_TemplateArgumentNode_2E97CF467782F7D519085603AD7A6F979CF62941.html" },
        { name: "sngcpp::ast::TemplateDeclarationNode", id: "class_46", level: 1, subject: false, hasDerivedClasses: false, link: "./class_TemplateDeclarationNode_C3E60CC2D83CB6A8AD00E259AC31ECADBECE6569.html" },
        { name: "sngcpp::ast::TemplateIdNode", id: "class_47", level: 1, subject: false, hasDerivedClasses: false, link: "./class_TemplateIdNode_A852BC0337977094554D7B57B6E2254321E7CE80.html" },
        { name: "sngcpp::ast::ThisCaptureNode", id: "class_48", level: 1, subject: false, hasDerivedClasses: false, link: "./class_ThisCaptureNode_52E7C10A006DD04EF3B18EFC785D28735A3CC166.html" },
        { name: "sngcpp::ast::ThisNode", id: "class_49", level: 1, subject: false, hasDerivedClasses: false, link: "./class_ThisNode_E2AB06AD44A4FC8E5CBC2EB718B6B6D77EC37676.html" },
        { name: "sngcpp::ast::TryStatementNode", id: "class_50", level: 1, subject: false, hasDerivedClasses: false, link: "./class_TryStatementNode_3C9E925D6F4DA97983073F4ACB6F1BA2B5C6CA30.html" },
        { name: "sngcpp::ast::TypeParameterNode", id: "class_51", level: 1, subject: false, hasDerivedClasses: false, link: "./class_TypeParameterNode_80AE4C948E43708AD4682F77F1D97C98B693EF82.html" },
        { name: "sngcpp::ast::TypedefNode", id: "class_52", level: 1, subject: false, hasDerivedClasses: false, link: "./class_TypedefNode_97C0EC0AC48A1196D83029269F6F6548B97B19CB.html" },
        { name: "sngcpp::ast::UnaryNode", id: "class_53", level: 1, subject: false, hasDerivedClasses: true, link: "./class_UnaryNode_E514E053A58973FBA3EA4848FF3935F602CE80DD.html" },
        { name: "sngcpp::ast::UsingDeclarationNode", id: "class_54", level: 1, subject: false, hasDerivedClasses: false, link: "./class_UsingDeclarationNode_47A7186316328E1256FA6692D853868EDE3D1A6F.html" },
        { name: "sngcpp::ast::UsingDirectiveNode", id: "class_55", level: 1, subject: false, hasDerivedClasses: false, link: "./class_UsingDirectiveNode_A0CBB938BF2FC81F8B1D12066937ABD2455063C2.html" },
        { name: "sngcpp::ast::WhileStatementNode", id: "class_56", level: 1, subject: false, hasDerivedClasses: false, link: "./class_WhileStatementNode_805401279A6B9274A85AF7DD47C22818EF7C71A4.html" }];
    drawDiagram(classes);
}

