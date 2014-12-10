#ifndef BREEZE_DECORATION_H
#define BREEZE_DECORATION_H

/*
 * Copyright 2014  Martin Gräßlin <mgraesslin@kde.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License or (at your option) version 3 or any later version
 * accepted by the membership of KDE e.V. (or its successor approved
 * by the membership of KDE e.V.), which shall act as a proxy
 * defined in Section 14 of version 3 of the license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "breezecolorsettings.h"

#include <KDecoration2/Decoration>

#include <QColor>
#include <QPalette>
#include <QVariant>

namespace KDecoration2
{
    class DecorationButton;
    class DecorationButtonGroup;
}

namespace Breeze
{
    class Decoration : public KDecoration2::Decoration
    {
        Q_OBJECT
            public:
            explicit Decoration(QObject *parent = nullptr, const QVariantList &args = QVariantList());
        virtual ~Decoration();

        void paint(QPainter *painter, const QRect &repaintRegion) override;

        const ColorSettings &colorSettings() {
            return m_colorSettings;
        }

        int captionHeight() const;

        public Q_SLOTS:
        void init() override;

        private Q_SLOTS:
        void recalculateBorders();
        void updateButtonPositions();
        void updateTitleBar();

        private:
        QRect captionRect() const;
        void createButtons();
        void paintTitleBar(QPainter *painter, const QRect &repaintRegion);
        void createShadow();
        ColorSettings m_colorSettings;
        QList<KDecoration2::DecorationButton*> m_buttons;
        KDecoration2::DecorationButtonGroup *m_leftButtons;
        KDecoration2::DecorationButtonGroup *m_rightButtons;
    };

}

#endif