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
        { name: "sngcpp::ast::Node", id: "class_0", level: 0, subject: false, hasDerivedClasses: true, link: "./class_Node_3B0B48506D44C685C8137A93FE6DDDBED7067F89.html" },
        { name: "sngcpp::ast::BinaryNode", id: "class_1", level: 1, subject: true, hasDerivedClasses: true, link: "./class_BinaryNode_26C91921CA6DD0BE63655ECBBFF8C167D358B1DE.html" },
        { name: "sngcpp::ast::AdditiveExpressionNode", id: "class_2", level: 2, subject: false, hasDerivedClasses: false, link: "./class_AdditiveExpressionNode_646644C21E683F933A76FB6E498CBEBBF11FC4C9.html" },
        { name: "sngcpp::ast::AndExpressionNode", id: "class_3", level: 2, subject: false, hasDerivedClasses: false, link: "./class_AndExpressionNode_EAA6E87D0F37B6C3E51FF2229988ECACD7CB19B1.html" },
        { name: "sngcpp::ast::AssignmentExpressionNode", id: "class_4", level: 2, subject: false, hasDerivedClasses: false, link: "./class_AssignmentExpressionNode_36B361F3EEBB5596F336CE1E115440D2CEB00567.html" },
        { name: "sngcpp::ast::BaseClassSpecifierSequenceNode", id: "class_5", level: 2, subject: false, hasDerivedClasses: false, link: "./class_BaseClassSpecifierSequenceNode_C72D3A70369BD87D826A1C9BCFEC824017A72543.html" },
        { name: "sngcpp::ast::CaptureSequenceNode", id: "class_6", level: 2, subject: false, hasDerivedClasses: false, link: "./class_CaptureSequenceNode_CC696618CB612F398AB52121B49EBCFF98981AC0.html" },
        { name: "sngcpp::ast::CommaExpressionNode", id: "class_7", level: 2, subject: false, hasDerivedClasses: false, link: "./class_CommaExpressionNode_B1935C8E9B57ADA853759BF33F7C9FF2F2DA3359.html" },
        { name: "sngcpp::ast::DeclarationSequenceNode", id: "class_8", level: 2, subject: false, hasDerivedClasses: false, link: "./class_DeclarationSequenceNode_444826008D36CF350146CAF1A142FB443400C179.html" },
        { name: "sngcpp::ast::EnumeratorSequenceNode", id: "class_9", level: 2, subject: false, hasDerivedClasses: false, link: "./class_EnumeratorSequenceNode_73ACB424CE484448001A1D5E3F05742EC9689138.html" },
        { name: "sngcpp::ast::EqualityExpressionNode", id: "class_10", level: 2, subject: false, hasDerivedClasses: false, link: "./class_EqualityExpressionNode_451EFFA2481F9F45A091C4CF6FBC0BEAF8A243E1.html" },
        { name: "sngcpp::ast::ExclusiveOrExpressionNode", id: "class_11", level: 2, subject: false, hasDerivedClasses: false, link: "./class_ExclusiveOrExpressionNode_3ABD305C501DFD212FF1FCD79B68D38A0738F02E.html" },
        { name: "sngcpp::ast::ExpressionSequenceNode", id: "class_12", level: 2, subject: false, hasDerivedClasses: false, link: "./class_ExpressionSequenceNode_03D6A15310B2531C99B39C361E7E3586DA7F410E.html" },
        { name: "sngcpp::ast::HandlerSequenceNode", id: "class_13", level: 2, subject: false, hasDerivedClasses: false, link: "./class_HandlerSequenceNode_D916768D9CA685962F0ED6219BABD986E23F57E1.html" },
        { name: "sngcpp::ast::InclusiveOrExpressionNode", id: "class_14", level: 2, subject: false, hasDerivedClasses: false, link: "./class_InclusiveOrExpressionNode_3214ECBF632686F7B1700FA0723AD8D07D7C032E.html" },
        { name: "sngcpp::ast::LogicalAndExpressionNode", id: "class_15", level: 2, subject: false, hasDerivedClasses: false, link: "./class_LogicalAndExpressionNode_C424A1DEBD3EAB9BAE998AABED45876D4ECD15C0.html" },
        { name: "sngcpp::ast::LogicalOrExpressionNode", id: "class_16", level: 2, subject: false, hasDerivedClasses: false, link: "./class_LogicalOrExpressionNode_5F01E810C790D91B4AE7F19F81257D5BA903AF7D.html" },
        { name: "sngcpp::ast::MemberInitializerSequenceNode", id: "class_17", level: 2, subject: false, hasDerivedClasses: false, link: "./class_MemberInitializerSequenceNode_97F2CC1363114BA6A6B2CE536B21C9825288B45E.html" },
        { name: "sngcpp::ast::MultiplicativeExpressionNode", id: "class_18", level: 2, subject: false, hasDerivedClasses: false, link: "./class_MultiplicativeExpressionNode_194B2D3A8A640406E728FE4BAD0E8C5AC7A46EA5.html" },
        { name: "sngcpp::ast::NestedIdNode", id: "class_19", level: 2, subject: false, hasDerivedClasses: false, link: "./class_NestedIdNode_0413C26AB3BDAED88580A82341C70AEBC0578E39.html" },
        { name: "sngcpp::ast::PMExpressionNode", id: "class_20", level: 2, subject: false, hasDerivedClasses: false, link: "./class_PMExpressionNode_5629B6FF862318FC8BF5BB40A325CB4F53EAEFD9.html" },
        { name: "sngcpp::ast::ParameterSequenceNode", id: "class_21", level: 2, subject: false, hasDerivedClasses: false, link: "./class_ParameterSequenceNode_2250E2D13F65B085EBA0A00FEC18439190DBB411.html" },
        { name: "sngcpp::ast::RelationalExpressionNode", id: "class_22", level: 2, subject: false, hasDerivedClasses: false, link: "./class_RelationalExpressionNode_6583AC7AE0D894AE3DCC0AFEB133CB1B7FC45943.html" },
        { name: "sngcpp::ast::ShiftExpressionNode", id: "class_23", level: 2, subject: false, hasDerivedClasses: false, link: "./class_ShiftExpressionNode_E11B8D46E97DD59B6D5B203D4A9F27B67C57B43C.html" },
        { name: "sngcpp::ast::SourceFileSequenceNode", id: "class_24", level: 2, subject: false, hasDerivedClasses: false, link: "./class_SourceFileSequenceNode_EA4B27A6A4CFF856C66D11F91A61E50A03FFF342.html" },
        { name: "sngcpp::ast::StatementSequenceNode", id: "class_25", level: 2, subject: false, hasDerivedClasses: false, link: "./class_StatementSequenceNode_0AA0650E957BB86C07F016304980D95A7B5F6DCD.html" },
        { name: "sngcpp::ast::TemplateArgumentSequenceNode", id: "class_26", level: 2, subject: false, hasDerivedClasses: false, link: "./class_TemplateArgumentSequenceNode_4EA9BC8EE2FA867B3692B25DEE7A4C59A861F36E.html" },
        { name: "sngcpp::ast::TemplateParameterSequenceNode", id: "class_27", level: 2, subject: false, hasDerivedClasses: false, link: "./class_TemplateParameterSequenceNode_8469DB0072167FAE81179E69307BAC7A8E9F6796.html" }];
    drawDiagram(classes);
}

