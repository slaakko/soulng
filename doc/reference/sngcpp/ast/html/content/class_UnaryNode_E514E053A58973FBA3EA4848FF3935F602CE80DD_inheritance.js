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
        { name: "sngcpp::ast::UnaryNode", id: "class_1", level: 1, subject: true, hasDerivedClasses: true, link: "./class_UnaryNode_E514E053A58973FBA3EA4848FF3935F602CE80DD.html" },
        { name: "sngcpp::ast::ArrowNode", id: "class_2", level: 2, subject: false, hasDerivedClasses: false, link: "./class_ArrowNode_D5F4EE9F04DA45CFBDA007DF3BB38425574A9348.html" },
        { name: "sngcpp::ast::AssignmentInitializerNode", id: "class_3", level: 2, subject: false, hasDerivedClasses: false, link: "./class_AssignmentInitializerNode_6522CF0B0160BB491A775C1C61705B36F0B11DCA.html" },
        { name: "sngcpp::ast::BracedInitializerListNode", id: "class_4", level: 2, subject: false, hasDerivedClasses: false, link: "./class_BracedInitializerListNode_4B5416D4B7D5845705A49B3D62854D8FBE985F72.html" },
        { name: "sngcpp::ast::CaseStatementNode", id: "class_5", level: 2, subject: false, hasDerivedClasses: false, link: "./class_CaseStatementNode_94117DE63309113D0C69F113C5C67B0EC893BB4A.html" },
        { name: "sngcpp::ast::CompoundStatementNode", id: "class_6", level: 2, subject: false, hasDerivedClasses: false, link: "./class_CompoundStatementNode_7AC886EA85388FFD32E851E8404E5F6DD11DEE50.html" },
        { name: "sngcpp::ast::ConstNode", id: "class_7", level: 2, subject: false, hasDerivedClasses: false, link: "./class_ConstNode_791F31FC6A66A9CEA27C44E85AC5727A94509E9E.html" },
        { name: "sngcpp::ast::CtorInitializerNode", id: "class_8", level: 2, subject: false, hasDerivedClasses: false, link: "./class_CtorInitializerNode_7445324D86539791E2D9816934E98F4E5D6E342F.html" },
        { name: "sngcpp::ast::DeclarationStatementNode", id: "class_9", level: 2, subject: false, hasDerivedClasses: false, link: "./class_DeclarationStatementNode_56981ECCE4AAD995F8EDB3BCC5CE4BB17C78FF5A.html" },
        { name: "sngcpp::ast::DefaultStatementNode", id: "class_10", level: 2, subject: false, hasDerivedClasses: false, link: "./class_DefaultStatementNode_68BB3EDA2C243E5BC80E7397389D27645BEED449.html" },
        { name: "sngcpp::ast::DeleteExpressionNode", id: "class_11", level: 2, subject: false, hasDerivedClasses: false, link: "./class_DeleteExpressionNode_A4FC110FE7CB621D52C19118DA061E0BD2CFA981.html" },
        { name: "sngcpp::ast::DotNode", id: "class_12", level: 2, subject: false, hasDerivedClasses: false, link: "./class_DotNode_D560426060C063A8546B2C8C79EB8598802EF710.html" },
        { name: "sngcpp::ast::ExplicitInstantiationNode", id: "class_13", level: 2, subject: false, hasDerivedClasses: false, link: "./class_ExplicitInstantiationNode_A4EE268EBC326C26A8E30AD0220D444DC5CA58FA.html" },
        { name: "sngcpp::ast::ExplicitSpecializationNode", id: "class_14", level: 2, subject: false, hasDerivedClasses: false, link: "./class_ExplicitSpecializationNode_46B261876632CEBF13974C19276B00936BDDB799.html" },
        { name: "sngcpp::ast::ExpressionInitializerNode", id: "class_15", level: 2, subject: false, hasDerivedClasses: false, link: "./class_ExpressionInitializerNode_83257C3B408A211519A78BB4C1268CF7106F49A0.html" },
        { name: "sngcpp::ast::ExpressionListInitializerNode", id: "class_16", level: 2, subject: false, hasDerivedClasses: false, link: "./class_ExpressionListInitializerNode_E33491DA42E5C8F345FF5CF8ECFBCFBE06AB3123.html" },
        { name: "sngcpp::ast::ExpressionStatementNode", id: "class_17", level: 2, subject: false, hasDerivedClasses: false, link: "./class_ExpressionStatementNode_214B8E296B636ADE9D97717653DF813740CD49D4.html" },
        { name: "sngcpp::ast::IdentifierCaptureNode", id: "class_18", level: 2, subject: false, hasDerivedClasses: false, link: "./class_IdentifierCaptureNode_C2C53BBA96D4F35D6B86F94DF54D1AA71F44EAEF.html" },
        { name: "sngcpp::ast::InvokeExpressionNode", id: "class_19", level: 2, subject: false, hasDerivedClasses: false, link: "./class_InvokeExpressionNode_9BB7176AE3AE3BABF44808E00B86F46FDC429F8A.html" },
        { name: "sngcpp::ast::LValueRefNode", id: "class_20", level: 2, subject: false, hasDerivedClasses: false, link: "./class_LValueRefNode_6266655218B2306C1470B102A910ABAE01C973F7.html" },
        { name: "sngcpp::ast::LabeledStatementNode", id: "class_21", level: 2, subject: false, hasDerivedClasses: false, link: "./class_LabeledStatementNode_DC29268FAC8D4DA2FB1EFCBBAD0698E174200656.html" },
        { name: "sngcpp::ast::NamespaceNode", id: "class_22", level: 2, subject: false, hasDerivedClasses: false, link: "./class_NamespaceNode_C242C0BE52F147B75B335B17D8D3D94DD30C3CB9.html" },
        { name: "sngcpp::ast::ParenthesizedExprNode", id: "class_23", level: 2, subject: false, hasDerivedClasses: false, link: "./class_ParenthesizedExprNode_A72F58521E415F4D3B8D0DC26418D8B3FEBECDE1.html" },
        { name: "sngcpp::ast::PointerNode", id: "class_24", level: 2, subject: false, hasDerivedClasses: false, link: "./class_PointerNode_E4F1E9C814E9352CE59C16E5487F40D5498F6675.html" },
        { name: "sngcpp::ast::PostfixDecNode", id: "class_25", level: 2, subject: false, hasDerivedClasses: false, link: "./class_PostfixDecNode_A91BBA6390FB3B09290B47719D47F47342871B34.html" },
        { name: "sngcpp::ast::PostfixIncNode", id: "class_26", level: 2, subject: false, hasDerivedClasses: false, link: "./class_PostfixIncNode_197D9857A93375594BCB0420A7594BB6F0A89E8C.html" },
        { name: "sngcpp::ast::RValueRefNode", id: "class_27", level: 2, subject: false, hasDerivedClasses: false, link: "./class_RValueRefNode_69543375254B64F0CC387CA5032AACFCE16B1F24.html" },
        { name: "sngcpp::ast::SubscriptExpressionNode", id: "class_28", level: 2, subject: false, hasDerivedClasses: false, link: "./class_SubscriptExpressionNode_9DD145DD7A819CC1ECC448AF56862BD71C90388A.html" },
        { name: "sngcpp::ast::ThrowExpressionNode", id: "class_29", level: 2, subject: false, hasDerivedClasses: false, link: "./class_ThrowExpressionNode_BDF3BE553E93877F3F53B533BD02C80CB4738F41.html" },
        { name: "sngcpp::ast::TypeExprNode", id: "class_30", level: 2, subject: false, hasDerivedClasses: false, link: "./class_TypeExprNode_0788344F072FE7A1D077B11B8056834449DF02FC.html" },
        { name: "sngcpp::ast::TypeIdExpressionNode", id: "class_31", level: 2, subject: false, hasDerivedClasses: false, link: "./class_TypeIdExpressionNode_BE744203EEC5AB94F32BA26CFB69A9A56A352488.html" },
        { name: "sngcpp::ast::UnaryExpressionNode", id: "class_32", level: 2, subject: false, hasDerivedClasses: false, link: "./class_UnaryExpressionNode_0158205C576BD308E68A0A8F334BB20449473A4E.html" },
        { name: "sngcpp::ast::VolatileNode", id: "class_33", level: 2, subject: false, hasDerivedClasses: false, link: "./class_VolatileNode_FF7BC932368393C334F366B0BD1BB2A9EB058085.html" }];
    drawDiagram(classes);
}

